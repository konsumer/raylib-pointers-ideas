import { raylib } from '@raylib/api'
import { writeFile } from 'fs/promises'

const detectRayValueStruct = s => /^\p{Lu}/u.test(s) && !s.endsWith('*')

let out = `// raylib-pointer wrapper generated at ${new Date().toISOString()}

#include "raylib.h"

`

const callFunction = (f, retHasValueStruct, inputHasValueStruct) => {
  let out = ''
  if (f.returnType !== 'void') {
    out += 'return '
    if (retHasValueStruct) {
      out += '&'
    }
  }
  out += `${f.name}(`

  const params = (f.params || []).map(p => p.name)

  if (inputHasValueStruct) {
    for (const p in f.params) {
      const param = f.params[p]
      if (detectRayValueStruct(param.type)) {
        params[p] = `&${params[p]}`
      }
    }
  }

  out += params.join(', ')
  out += ')'

  return out
}

const pcount = 0
for (const f of raylib.functions) {
  const inputHasValueStruct = !!f?.params?.find(p => detectRayValueStruct(p.type))
  const retHasValueStruct = detectRayValueStruct(f.returnType)

  // console.log({ ...f, inputHasValueStruct, retHasValueStruct })

  if (inputHasValueStruct || retHasValueStruct) {
    const pString = (f?.params || []).map(p => (detectRayValueStruct(p.type) ? `${p.type}*` : p.type).replace(' *', '*') + ` ${p.name}`).join(', ')
    const ret = retHasValueStruct ? `${f.returnType}*` : f.returnType
    out += `
// ${f.description}
${ret} RP_${f.name}(${pString}) {
  ${callFunction(f, retHasValueStruct, retHasValueStruct)}
}

`
  }
}

console.log(out)
