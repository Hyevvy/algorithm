function solution(x) {
    var answer = true;
    let sum=0;
    for(let i=x; i>0; i=parseInt(i/10)){
        sum+=i%10;
    }
    if(x%sum!=0) return false;
    return answer;
}
