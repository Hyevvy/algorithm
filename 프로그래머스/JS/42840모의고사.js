function solution(answers) {
    var answer = [];
    var temp3=[3,3,1,1,2,2,4,4,5,5];
    var temp2=[2, 1, 2, 3, 2, 4, 2, 5];
    var mathgiveup1 = [];
    var mathgiveup2 = [];
    var mathgiveup3 = [];
    for(let i=0;i<answers.length;i++) {
        mathgiveup1.push(i%5 + 1);
        mathgiveup2.push(temp2[i%8]);
        mathgiveup3.push(temp3[i%10]);
    }
    let checkArray=[0,0,0];
    for(let i=0; i<answers.length; i++){
        if(mathgiveup1[i]===answers[i]) checkArray[0]++;
        if(mathgiveup2[i]===answers[i]) checkArray[1]++;
        if(mathgiveup3[i]===answers[i]) checkArray[2]++;
    }
    let max=checkArray[0]; 
    for(let i=1;i<3;i++){
       if(max<checkArray[i]) {max=checkArray[i];}
   }
    for(let i=0;i<3;i++){
        if(max===checkArray[i]) answer.push(i+1);
    }
   
    return answer;
}