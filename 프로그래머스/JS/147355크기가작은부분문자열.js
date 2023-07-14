function solution(t, p) {
  var answer = 0;
  for (let i = 0; i < t.length - p.length + 1; i++) {
    if (Number(t.substring(i, i + p.length)) <= Number(p)) {
      answer++;
    }
  }
  return answer;
}

// 다른 사람의 풀이

function solution(t, p) {
  let count = 0;
  for (let i = 0; i <= t.length - p.length; i++) {
    let value = t.slice(i, i + p.length);
    if (+p >= +value) count++;
  }
  return count;
}
