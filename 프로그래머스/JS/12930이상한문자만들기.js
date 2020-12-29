function solution(s) {
    var answer = s.split('');
    var temp;
    let index=0;
    var added='';
    for(let i=0; i<s.length; i++){
        if(s[i]===' ') {index=0;}
        else{
          if(index%2===0) {temp=s.toUpperCase(); answer[i]=temp[i];}
          else {temp = s.toLowerCase();}
            answer[i]=temp[i];
          index++;
        }
    }
    answer = answer.join('');
    return answer;
}