function solution(sides) {
  var answer;
  sides.sort();
  answer = sides[2] < sides[0] + sides[1] ? 1 : 2;
  return answer;
}
