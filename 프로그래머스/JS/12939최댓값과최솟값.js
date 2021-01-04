function solution(s) {
    var answer = [];
    var temp = s.split(' ');
    answer.push(Math.min(...temp));
    answer.push(Math.max(...temp));
    answer=answer.join(" ");
    return answer;
}
