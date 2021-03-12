function CreatList (cont, text = 'Text'){
    let list = [];
    list[0] = '<ul>'
    for (let flag =1; flag <= cont; flag++){
        list[flag] = `<li>${text} ${flag}</li>`
    }
    list.push('</ul>')
    return list;
}

module.exports = CreatList