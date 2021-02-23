const soma_Impares = require('./somadorImpares.js')
const soma = ((x, value) => x + value)
const product = ((x, value) => x * value)

const array = [24,69,25]
console.log(array.reduce(soma))
console.log(array.reduce(product))
console.log(soma_Impares(array))
