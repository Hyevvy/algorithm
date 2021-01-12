function solution(n) {
    var answer = [];
    let num = 0;
    
    for(let i=n; i>0; i=parseInt(i/3)){
        answer.push(i%3);
    }
    for(let i=0; i<answer.length; i++){
        num += answer[i] * Math.pow(3, answer.length-i-1);
    }
    return num;
}
