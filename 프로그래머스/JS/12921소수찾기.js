function checkPrime(n){
    let state=0;//소수일 때
    for(let i=2;i<n;i++){
        if(n%i===0) {state=1; return state;}
    }
    return state;
}
function solution(n) {
    var answer = 0;//소수의 개수
    for(let i=2; i<=n; i++){
        if(i===2 || checkPrime(i)===0) answer++;
    }
    return answer;
}