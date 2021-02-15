const enviar = document.querySelector('input#calcular')
enviar.addEventListener('click', click)

var result = undefined
var a = undefined

function click(){
    const number1 = document.querySelector('input#n1');
    const number2 = document.querySelector('input#n2');
    const operation = document.querySelector('input#operador');
    const res = document.querySelector('div#resposta');
    const opr = String(operation.value)
    const n1 = Number(number1.value);
    const n2 = Number(number2.value);

    if (opr === '+') {
        result = n1 + n2
        a = 'Soma';
    } else if (opr === '-'){
        result = n1 - n2;
        a = 'Subtração';
    }else if (opr === '*' || opr === 'x'){
        result = n1 * n2;
        a = 'Multiplicação';
    }else if (opr === '/'){
        result = n1 / n2;
        a = 'Divisão';
    }else{
        result = 'Valor não encontrado'
        a = 'Operação';
    }   
    res.innerHTML = `O Resultado da ${a} foi <b>${result}</b>`;
}
