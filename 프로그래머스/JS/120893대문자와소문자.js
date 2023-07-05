function solution(my_string) {
  var answer = "";
  for (let ch of my_string) {
    if (ch >= "a" && ch <= "z") {
      answer += ch.toUpperCase();
    } else answer += ch.toLowerCase();
  }
  return answer;
}
