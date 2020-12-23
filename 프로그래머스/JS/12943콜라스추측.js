function solution(num) {
    var answer = 0;
    while(1){
        if(answer >= 500) return -1;
        if(num===1) return answer;
        if(num%2===0) num=num/2;
        else {
            num=(num*3)+1;
        }
        answer++;
    }
    return answer;
}