var b = document.querySelector('input#enviar')
b.addEventListener('click',click)

var result = undefined
function click(){
    const r = document.querySelector('input#raio')
    const a = document.querySelector('input#und')
    const resposta = document.querySelector('div.res')
    const raio = Number(r.value)
    const und = String(a.value).toUpperCase()
    const area = 3.14159 * (raio**2)
    if (und == 'KM' || und == 'KILOMETRO' ){
        result = 'km'
    }else if (und == 'CM' || und == 'CENTIMETRO'){
        result = 'cm'
    }else if (und == 'M' || und == 'METRO'){
        result = 'm'
    }else if (und == "MM" || und == 'mILIMETRO'){
        result = 'mm'
    }else{
        result ='Unidade não definida'
    }
    resposta.innerHTML = `A área do círculo = ${area} ${result}`
}