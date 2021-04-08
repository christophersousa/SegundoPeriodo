import flags from './model/flags.js';

/*for(const bandeiras of flags){
    const main = document.querySelector('.row')
    const ViewBandeiras = createBandeiras(bandeiras);
    main.insertAdjacentHTML('beforeend', ViewBandeiras)
}*/
let fim = 50;
let inicio = 0;

function createFlag(){
    let flag = flags
    let slice = flag.slice(inicio, fim)
    createBandeiras(slice)
    inicio = fim;
    fim += 50;
}

function createBandeiras(flagsBandeiras) {
    for(const bandeiras of flagsBandeiras){
        const main = document.querySelector('.row')
        const ViewBandeiras = viewBandeiras(bandeiras);
        main.insertAdjacentHTML('beforeend', ViewBandeiras)
    }
}

function viewBandeiras(bandeiras){
    return `<div class="flag col-2 my-2 text-center">
        <img src="${bandeiras.image}" alt="United Arab Emirates">
        <div>${bandeiras.id.toUpperCase()}</div>
        <p>${bandeiras.name}</p>
      </div>`;
}

window.addEventListener("scroll", function() { 
    const percentageHeight = (window.scrollY + window.innerHeight) / document.body.scrollHeight; 
    if ( percentageHeight >= 0.99) {
        createFlag()
    } 
});

createFlag()