function solution(my_string) {
  var answer = "";
  for (let i = 0; i < my_string.length; i++) {
    let currentChar = my_string[i];
    if (
      currentChar != "a" &&
      currentChar != "e" &&
      currentChar != "i" &&
      currentChar != "o" &&
      currentChar != "u"
    )
      answer += currentChar;
  }
  return answer;
}
