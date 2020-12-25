function solution(n)
{
    var answer = 0;
    for(let i=n; i>0; i=parseInt(i/10)){
        answer += i%10;
    }
    return answer;
}