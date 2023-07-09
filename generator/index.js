let output = ''
const raylib = require('@raylib/api').raylib

const structs = []
for (const struct of raylib.structs) {
    structs.push(struct.name)
}

for (const func of raylib.functions) {
    console.log('/**')
    console.log(` * ${func.description}`)
    console.log(' */')

    let callBefore = ''
    let callAfter = ''
    let params = []
    let paramsCall = []
    let returnType = 'void'
    let outputReturn = ''

    // Return
    if (structs.includes(func.returnType)) {
        params.push(`${func.returnType}* output`)
        outputReturn = `${func.returnType} val = `
        callAfter = `\n    memcpy(output, &val, sizeof(${func.returnType}));`
    }
    else {
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
            }
            else {
                params.push(`${param.type} ${param.name}`)
                paramsCall.push(`${param.name}`)
            }
        }
    }

    console.log(`${returnType} rp_${func.name}(${params.join(', ')}) {
    ${callBefore}${outputReturn}${func.name}(${paramsCall.join(', ')});${callAfter}
}
    `)
}