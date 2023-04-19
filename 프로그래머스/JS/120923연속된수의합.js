function solution(num, total) {
  var answer = [];
  let sum = 0;
  let stand = 0;

  for (let i = 0; i < num; i++) {
    sum += i;
  }
  stand = (total - sum) / num;

  for (let i = 0; i < num; i++) {
    answer.push(stand + i);
  }
  return answer;
}
