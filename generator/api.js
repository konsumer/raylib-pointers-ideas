import { raylib } from '@raylib/api'
import { writeFile } from 'fs/promises'

const [,,filename] = process.argv

if (!filename) {
  console.error('Usage: cnative <FILENAME>')
  process.exit(1)
}

const out = []

out.push(`// pointer-raylib
// File generated on ${(new Date()).toISOString()}

#ifdef RP_NATIVE
  #include "raylib.h"
#endif // RP_NATIVE

#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef RLP_EXPORT
  #define RLP_EXPORT
#endif

// TODO: not sure how to map these
#ifndef RP_NATIVE
  typedef void rAudioProcessor;
  typedef void rAudioBuffer;
  typedef void* TraceLogCallback;
  typedef void* LoadFileDataCallback;
  typedef void* SaveFileDataCallback;
  typedef void* LoadFileTextCallback;
  typedef void* SaveFileTextCallback;
  typedef void* AudioCallback;

`)

const mappedStructs = raylib.structs.reduce((a, c) => ({...a, [c.name]: c}), {})
const structs = Object.keys(mappedStructs)

const aliases = {}
for (const alias of raylib.aliases) {
  aliases[alias.type] = aliases[alias.type] || []
  aliases[alias.type].push(alias)
  structs.push(alias.name)
}

for (const struct of Object.values(mappedStructs)) {
  const fields = struct.fields.map(field => {
      const m = (/([a-zA-Z0-9_]+)\[([0-9]+)\]/gm).exec(field.type)
      if (m) {
        field.type = m[1]
        field.name = `${field.name}[${m[2]}]`
      }
      return field
    })
    out.push(`
/*
 * ${struct.description}
 */
typedef struct ${struct.name} {
${fields.map(f => `  ${f.type} ${f.name}; // ${f.description}`).join('\n')}
} ${struct.name};`)
    for (const alias of (aliases[struct.name] || [])) {
      out.push(`\n// ${alias.description}\ntypedef ${alias.type} ${alias.name};`)
    }
}

// only do colors
out.push('')
for (const d of raylib.defines) {
  if (typeof d.value === 'string' && d.value.includes('CLITERAL(Color)')){
    out.push(`Color * rp_${d.name} = ${d.value.replace('CLITERAL(Color)', '&((Color) ')}); // ${d.description}`)
  }
}
out.push('#endif // RP_NATIVE\n')

// TODO: enums and a few other defines

const end = []

for (const func of raylib.functions) {
  out.push('/**')
  out.push(` * ${func.description}`)
  out.push(' */')

  let callBefore = ''
  let callAfter = ''
  const params = []
  const paramsCall = []
  let returnType = 'void'
  let outputReturn = ''

  // Return
  if (structs.includes(func.returnType)) {
    params.push(`${func.returnType}* output`)
    outputReturn = `${func.returnType} val = `
    callAfter = `\n    memcpy(output, &val, sizeof(${func.returnType}));`
  } else {
    returnType = func.returnType
  }

  if (returnType != 'void') {
    callBefore = 'return ' + callBefore
  }

  // Params
  if (func.params) {
    for (const param of func.params) {
      if (structs.includes(param.type)) {
        params.push(`${param.type}* ${param.name}`)
        paramsCall.push(`*${param.name}`)
      } else {
        params.push(`${param.type} ${param.name}`)
        paramsCall.push(`${param.name}`)
      }
    }
  }

  // not a huge fan of this, but it gets it building for now
  for (const p in params) {
    params[p] = params[p].replace('...', 'char*')
  }

  out.push(`RLP_EXPORT ${returnType} rp_${func.name}(${params.join(', ')});\n`)
 

  end.push(`${returnType} rp_${func.name}(${params.join(', ')}) {
    ${callBefore}${outputReturn}${func.name}(${paramsCall.join(', ')});${callAfter}
}
    `)
}

out.push(`
#ifdef RP_NATIVE
${end.join('\n')}
#endif // RP_NATIVE
`)

await writeFile(filename, out.join('\n'))
