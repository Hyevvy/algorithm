function solution(babbling) {
  var answer = 0;
  const ableToSay = ["aya", "ye", "woo", "ma"];
  for (let j = 0; j < babbling.length; j++) {
    for (let k = 0; k < 4; k++) {
      if (babbling[j].includes(ableToSay[k])) {
        babbling[j] = babbling[j].replace(ableToSay[k], "0");
      }
    }
  }

  for (let i = 0; i < babbling.length; i++) {
    let canSpeak = true;
    for (let j = 0; j < babbling[i].length; j++) {
      if (canSpeak == false) break;
      if (babbling[i][j] !== "0") canSpeak = false;
    }
    if (canSpeak == true) answer++;
  }

  return answer;
}
