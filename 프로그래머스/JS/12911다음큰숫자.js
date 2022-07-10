function getOne(n){
    var one=0;
     for(let i=n; i>0; i=parseInt(i/2)){
        if(i%2===1) one++;
    }
   // console.log(one);
    return one;
}
function solution(n) {
    var answer = 0;
    var oneN = getOne(n);
    var oneT=0;
    for(let i=n+1; ; i++){
        oneT=getOne(i);
     //   console.log(i,"일때",oneT);
        if(oneT===oneN) { return i; break;}
    }
   // console.log(oneN);
    return answer;
    
}
