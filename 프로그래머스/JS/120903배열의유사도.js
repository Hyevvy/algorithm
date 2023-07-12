function solution(s1, s2) {
  var answer = 0;
  for (let x of s1) {
    if (s2.indexOf(x) !== -1) answer++;
  }
  return answer;
}
