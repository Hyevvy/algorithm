function solution(n) {
    var answer = [];
    for(let i=n; i>0; i=parseInt(i/10)){
       // console.log((i%10));
        answer.push(i%10);
    }
    return answer;
}