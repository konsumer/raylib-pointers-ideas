import api from '@raylib/api'
import { writeFile } from 'fs/promises'

const { raylib, raymath } = api

const [,,filename] = process.argv

if (!filename) {
  console.error('Usage: cnative <FILENAME>')
  process.exit(1)
}

const out = []

out.push(`// pointer-raylib API
// File generated on ${(new Date()).toISOString()}

#include <stdbool.h>

#ifndef RLP_EXPORT
  #define RLP_EXPORT
#endif

typedef struct float2 {
    float v[2];
} float2;

typedef struct float4 {
    float v[4];
} float4;

typedef struct char32 {
    char v[32];
} char32;

// TODO: not sure how to map these
typedef void rAudioProcessor;
typedef void rAudioBuffer;

`)

const mappedStructs = raylib.structs.reduce((a, c) => ({...a, [c.name]: c}), {})

const aliases = {}
for (const alias of raylib.aliases) {
  aliases[alias.type] = aliases[alias.type] || []
  aliases[alias.type].push(alias)
}

const structs = Object.keys(mappedStructs)


const rf = /([a-zA-Z0-9_]+)\[([0-9]+)\]/gm

for (const struct of Object.values(mappedStructs)) {
  const fields = struct.fields.map(field => {
      // convert float[16] into float16
      const m = rf.exec(field.type)
      if (m) {
        field.type = `${m[1]}${m[2]}`
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
      out.push(`// ${alias.description}\ntypedef ${alias.type} ${alias.name};`)
    }

    if (struct.name === 'Matrix') {
      out.push(`
typedef struct Matrix2 {
    Matrix v[2];
} Matrix2;
`)
    }
}

// only do colors
out.push('')
for (const d of raylib.defines) {
  if (typeof d.value === 'string' && d.value.includes('CLITERAL(Color)')){
    out.push(`Color * rp_${d.name} = ${d.value.replace('CLITERAL(Color)', '&((Color) ')}); // ${d.description}`)
  }
}
out.push('')

for (const func of raylib.functions) {
  // TODO: leaving out the cllback functions, because not sure how to deal with them
  if (func.name.includes('Callback') || func.name.includes('Detach') || func.name.includes('Attach')) {
    continue
  }

  out.push('/**')
  out.push(` * ${func.description}`)
  out.push(' */')

  let callBefore = ''
  let callAfter = ''
  const params = []
  let returnType = 'void'

  // Return
  if (structs.includes(func.returnType)) {
    params.push(`${func.returnType}* output`)
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
      } else {
        params.push(`${param.type} ${param.name}`)
      }
    }
  }

  // not a huge fan of this, but it gets it building for now
  for (const p in params) {
    params[p] = params[p].replace('...', 'char*')
  }
 

  out.push(`RLP_EXPORT ${returnType} rp_${func.name}(${params.join(', ')});\n`)
}

await writeFile(filename, out.join('\n'))
