const api = await fetch('https://raw.githubusercontent.com/raysan5/raylib/5.0/parser/output/raylib_api.json').then(r => r.json())

// rudimentary struct-value check
const detectRayValueStruct = s => /^\p{Lu}/u.test(s) && !s.includes('*')

// output the call of the original function
const outputCall = (name, params) => {
  return `${name}(${params.map(p => p.var).join(', ')});`
}

const out = []

const semver = `${api.defines.find(d => d.name === 'RAYLIB_VERSION_MAJOR').value}.${api.defines.find(d => d.name === 'RAYLIB_VERSION_MINOR').value}.${api.defines.find(d => d.name === 'RAYLIB_VERSION_PATCH').value}`

out.push(`// raylib-pointer wrapper generated at ${new Date().toISOString()} for ${semver}`)
out.push('\n#include "raylib.h"\n')
out.push('#ifndef RLP_EXPORT\n  #define RLP_EXPORT\n#endif\n')

for (const { name, description, returnType, params = [] } of api.functions) {
  // these use vargs, which can be done in other ways
  if (['TraceLog', 'TextFormat'].includes(name)) {
    continue
  }

  // these are undefined for some reason
  if (['DrawLineBezierQuad', 'DrawLineBezierCubic', 'DrawLineBSpline', 'DrawLineCatmullRom'].includes(name)) {
    continue
  }

  const fout = { returnType, params: [...params] }
  if (detectRayValueStruct(returnType)) {
    fout.returnType = 'void'
    fout.params.unshift({
      type: `${returnType.trim()}*`,
      name: 'rp_retVal',
      var: '*rp_retVal'
    })
  }

  for (const p of fout.params) {
    if (detectRayValueStruct(p.type)) {
      p.type = `${p.type.trim()}*`
      p.var = `*${p.name}`
    } else {
      p.type = p.type.trim().replace(' *', '*')
      p.var = p.name
    }
  }

  out.push(`// ${description}`)
  out.push(`RLP_EXPORT ${fout.returnType} rp_${name} (${fout.params.map(p => `${p.type} ${p.name}`).join(', ')}) {`)

  if (fout.returnType !== 'void') {
    out.push(`  return ${outputCall(name, fout.params)}`)
  } else {
    if (fout.params[0]?.name === 'rp_retVal') {
      out.push(`  *rp_retVal = ${outputCall(name, fout.params.slice(1))}`)
    } else {
      out.push(`  ${outputCall(name, fout.params)}`)
    }
  }
  out.push('}\n')
}

console.log(out.join('\n'))
