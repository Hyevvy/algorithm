function solution(numbers) {
    var answer = [];
    var sumArray = [];
    for(let i=0;i<numbers.length; i++){
        for(let j=0; j<numbers.length; j++){
            if(i!=j){
            let added=numbers[i] + numbers[j];
            if(sumArray.indexOf(added) === -1 )
                 sumArray.push(added);
            }
        }
    }
    sumArray.sort(function(a, b)  {
      if(a > b) return 1;
      if(a === b) return 0;
      if(a < b) return -1;
    });
    answer = sumArray;
    return answer;
}