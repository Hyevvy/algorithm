function getP(s){
    let sum=0;
    for(let i=0;i<s.length;i++){
        if(s[i]==='p') sum++;
    }
    return sum;
}
function getY(s){
    let sum=0;
    for(let i=0;i<s.length;i++){
        if(s[i]==='y') sum++;
    }
    return sum;
}
function solution(s){
    var answer = true;
    s = s.toLowerCase();
    if(getP(s)===getY(s)) answer = true;
    else answer = false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    return answer;
}