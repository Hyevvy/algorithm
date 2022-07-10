function solution(n) {
    var answer = 0;
    let num=[];
    for(let i=n; i>0; i=parseInt(i/10))
        num.push(i%10);
    num.sort(function(a,b){
        return b-a;
    });
    answer = Number(num.join(''));
    return answer;
}
