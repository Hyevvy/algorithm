function solution(d, budget) {
    var answer = 0;
    d.sort((a,b)=>(a-b));
    let sum=0;
    for(let i=0; i<d.length; i++){
       sum+=d[i];
        if(sum>budget) break;
        answer++;
    }
    return answer;
}
