function somaImpares(x){
    result = 0
    for(value of x){
      if(value % 2 == 1){
        result+=value
      }
    }
    return result
}

/*
*/

module.exports = somaImpares