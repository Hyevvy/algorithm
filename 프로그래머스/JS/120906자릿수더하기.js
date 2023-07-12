function solution(n) {
  var answer = 0;
  String(n)
    .split("")
    .map((it) => (answer += Number(it)));
  return answer;
}
