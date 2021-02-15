var a = document.querySelector('input#soma')
       a.addEventListener('click', somar)

       function somar(){
           const n1 = document.querySelector('input#numero1')
           const n2 = document.querySelector('input#numero2')
           const res = document.querySelector('div.Resultado')
           const number_1 = Number(n1.value)
           const number_2 = Number(n2.value)
           const somar = number_1 + number_2
           res.innerHTML = `O resultado da soma do número ${number_1} mais o ${number_2} é <b>${somar}</b>`
       }