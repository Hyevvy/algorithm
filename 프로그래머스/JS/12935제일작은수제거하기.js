function solution(s) {
    var answer = true;
    var arr = s.split("");
    if(s.length ===4 || s.length ===6){
        for(let i=0;i<s.length;i++){
            if(arr[i]>=0 && arr[i]<=9) continue;
            else answer = false;
        }
    }
    else answer = false;
    return answer;
}