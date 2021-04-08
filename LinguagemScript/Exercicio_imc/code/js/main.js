const alturaElemento = document.querySelector('input#altura')
const pesoElemento = document.querySelector('input#peso')
const imcElemento = document.querySelector('input#imc')
const imcButtom = document.querySelector('input.btn')



function resultImc(sexo, peso, altura){
    var calcMIC = peso/(altura **2)
    console.log(calcMIC)

    if (sexo == 'masculino'){
        if (calcMIC < 20.7){
            return `Abaixo do Peso`;

        }else if (calcMIC > 20.7 && calcMIC <26.4){
            return  `Peso Normal`;

        }else if (calcMIC > 26.4 && calcMIC < 27.8){
            return `Marginalmente Acima do Peso`

        }else if (calcMIC > 27.8 && calcMIC < 31.1){
            return `Acima do Peso Ideal`
            
        }else{
            return `Obeso`

        }

    } else if (sexo == 'feminino'){

        if (calcMIC < 19.1){
            return `Abaixo do Peso`;
        
        }else if (calcMIC > 19.1 && calcMIC < 25.8){
            return `Peso Normal`;
           
        }else if (calcMIC > 25.8 && calcMIC < 27.3){
            return `Marginalmente Acima do Peso`;
           
        }else if (calcMIC > 27.3 && calcMIC < 32.3){
            return `Acima do Peso Ideal`;
            
        }else{
            return `Obesa`;
            
        }
    
    }
    
}

function calculadoraDeIMC(){
    const altura = Number(alturaElemento.value)
    const peso = Number(pesoElemento.value)
    const sexo = document.querySelector('input:checked').value
    console.log(sexo)
    const result = resultImc(sexo, peso, altura)
    imcElemento.value = result
    estilização(result)
}


function limpar() {
    alturaElemento.value = ''
    pesoElemento.value = ''
    imcElemento.value = ''
    alturaElemento.focus()
}

function hideBorder() {
    imcElemento.setAttribute('class', 'form-control form-control-lg')
}

document.addEventListener('keyup', function(evento2){
    if (evento2.key == 'Escape') {
        limpar()
        hideBorder()
      } else if (evento2.key == 'Enter') {
        calculadoraDeIMC()
      }
})


const border_style = {
    'Abaixo do Peso': 'border border-warning bg-warning text-white',
    'Peso Normal': 'border border-sucess bg-success text-white',
    'Marginalmente Acima do Peso': 'border border-warning bg-warning text-white',
    'Acima do Peso Ideal': 'border border-warning bg-warning text-white',
    'Obeso': 'border border-danger bg-danger text-white',
    'Obesa': 'border border-danger bg-danger text-white',
}

function estilização(resultado) {
    imcElemento.setAttribute('class', `form-control form-control-lg ${border_style[resultado]}`)
  }
