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



_____________________________________

 stack 사용 
 
 function solution(s){
    var answer = true;
    if(s[0]!=='(' || s[s.length-1]!==')') return false;
    let stack = [];
    for(let i=0; i<s.length; i++){
        if(s[i]==='(') {
            stack.push('(');
        }
        else if(s[i]===')'){
            if(stack.length==0) return false;
            stack.pop();
        }
    }
    if(stack.length!=0) return false;
    return answer;
}
