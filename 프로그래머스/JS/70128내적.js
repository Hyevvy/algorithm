function solution(a, b) {
  var answer = 0;
  for(let i=0, j=0; i<a.length; i++,j++){
      answer += a[i]*b[j];
  }
  return answer;
}