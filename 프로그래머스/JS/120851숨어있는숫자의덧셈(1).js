function solution(my_string) {
  var answer = 0;
  for (let x of my_string) {
    if (x >= 0 && x <= 9) {
      answer += Number(x);
    }
  }
  return answer;
}
