import { raylib } from '@raylib/api'
import { writeFile } from 'fs/promises'

const [,,filename] = process.argv

if (!filename) {
  console.error('Usage: generate <FILENAME>')
  process.exit(1)
}

const out = []

out.push(`// pointer-raylib
// File generated on ${(new Date()).toISOString()}

#include "raylib.h"
#include <memory.h>
#include <stdlib.h>

// TODO: put more in here for wasm, etc
#if defined(_WIN32)
    #if defined(BUILD_LIBTYPE_SHARED)
        #if defined(__TINYC__)
            #define __declspec(x) __attribute__((x))
        #endif
        #define RLP_EXPORT __declspec(dllexport)
    #elif defined(USE_LIBTYPE_SHARED)
        #define RLP_EXPORT __declspec(dllimport)
    #endif
#endif

#ifndef RLP_EXPORT
    #define RLP_EXPORT
#endif

`)

const structs = []
for (const struct of raylib.structs) {
  structs.push(struct.name)
}

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

  // not a huge fan of some of these replacements, but it gets it building for now
  for (const p in params) {
    params[p] = params[p].replace('...', 'char*')
  }
 

  out.push(`RLP_EXPORT ${returnType} rp_${func.name}(${params.join(', ')}) {
    ${callBefore}${outputReturn}${func.name}(${paramsCall.join(', ')});${callAfter}
}
    `)
}

await writeFile(filename, out.join('\n'))
