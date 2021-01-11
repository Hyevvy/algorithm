function solution(s){
    var answer = true;
    if(s[0]===')' || s[s.length-1]==='(') return false;
    else {
    let open =0;
    let close =0;
    for(let i=0;i<s.length;i++){
        if(s[i]==='(') open++;
        else if(s[i]===')')close++;
        if(close>open) return false;
    }
    if(open!=close) answer = false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    console.log('Hello Javascript')
    }
    return answer;
}
