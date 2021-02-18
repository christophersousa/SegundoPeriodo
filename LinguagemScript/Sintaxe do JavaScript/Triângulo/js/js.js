const a = document.querySelector('input#enviar')
a.addEventListener('click', click)


function click(){
    const number1 = document.querySelector('input#n1')
    const number2 = document.querySelector('input#n2')
    const number3 = document.querySelector('input#n3')
    const res = document.querySelector('div#res')
    var n1 = Number(number1.value)
    var n2 = Number(number2.value)
    var n3 = Number(number3.value)

    if (n1 > 0 & n2 > 0 & n3 > 0 ){

        if (n1 == 1 & n2 ==1 & n3 == 3){
            var result = 'Não é um Triangulo'
        }else if (n1 == 2 & n2 == 4 & n3 == 2){
            var result = 'Não é um Triangulo'
        }else if (n1 == n2 & n1 == n3 & n2 == n3){
            var result = 'Triângulo equilateral'
        } else if (n1 != n2 & n1 == n3 || n1 != n3 & n1 == n2 || n2 != n3 & n2 == n1 || n2 == n3 & n2 != n1){
            var result = 'Triângulo isosceles'
        }else if (n1 != n2 & n1 != n3 & n2 != n3){
            var result = 'Triângulo scalene'
        } 


    }else{
        var result = 'não é um triangulo '
    }

    res.innerHTML = `<b>${result}</b>`
}