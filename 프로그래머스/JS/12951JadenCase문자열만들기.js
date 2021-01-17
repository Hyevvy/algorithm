function solution(s) {
    var answer=[];
    answer[0] = s[0].toUpperCase();
    let state= 0; //빈칸이 아닌 경우
    for(let i=1; i<s.length; i++){
        if(s[i]==' ') {
            state=1;
        }
        else if(state==1) {
            answer[i] = s[i].toUpperCase();
            state=0;
            continue;
        }
        answer[i] = s[i].toLowerCase();
    }
    answer = answer.join('');
    return answer;
}
