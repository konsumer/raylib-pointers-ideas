// this will generate bunjs ffi wrapper for raylib

const api = await fetch('https://raw.githubusercontent.com/raysan5/raylib/5.0/parser/output/raylib_api.json').then(r => r.json())

// rudimentary struct-value check
const detectRayValueStruct = s => /^\p{Lu}/u.test(s) && !s.includes('*')

const out = []

const semver = `${api.defines.find(d => d.name === 'RAYLIB_VERSION_MAJOR').value}.${api.defines.find(d => d.name === 'RAYLIB_VERSION_MINOR').value}.${api.defines.find(d => d.name === 'RAYLIB_VERSION_PATCH').value}`

out.push(`// raylib-pointer bun ffi generated at ${new Date().toISOString()} for ${semver}\n`)

for (const { name, description, fields } of api.structs) {
  out.push(`// ${description}`)
  out.push(`export class ${name} {`)
  out.push('  constructor (init = {}, _address) {')
  out.push('  }')
  out.push('}')
  out.push('')
}

for (const { name, type, value, description } of api.defines) {
  if (!['MACRO', 'GUARD', 'UNKNOWN'].includes(type)) {
    if (description) {
      out.push(`// ${description}`)
    }
    let val = value

    if (type === 'STRING') {
      val = `'${val}'`
    }

    if (type === 'FLOAT_MATH') {
      val = val.replace(/f/g, '')
    }

    if (type === 'COLOR') {
      val = val.replace(/CLITERAL\(Color\){ ([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+) }/, 'new Color({ r: $1, g: $2, b: $3, a: $4 })')
    }

    out.push(`export const ${name} = ${val}`)
    out.push('')
  }
}

console.log(out.join('\n'))
