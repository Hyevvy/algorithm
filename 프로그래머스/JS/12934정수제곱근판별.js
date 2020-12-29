function solution(n) {
  var answer = 0;
  var num=Math.sqrt(n);
  if(Number.isInteger(num)===true) answer =(num+1)*(num+1);
  else answer = -1;
  return answer;
}