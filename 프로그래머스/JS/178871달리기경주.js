function solution(players, callings) {
  let playersMap = new Map();
  for (let i = 0; i < players.length; i++) {
    playersMap.set(players[i], i);
  }

  for (let i = 0; i < callings.length; i++) {
    const currentPlayerIdx = playersMap.get(callings[i]); //현재 추월한 선수
    const temp = players[currentPlayerIdx - 1]; // 추월당한 선수
    players[currentPlayerIdx - 1] = players[currentPlayerIdx];
    players[currentPlayerIdx] = temp;
    playersMap.set(callings[i], currentPlayerIdx - 1);
    playersMap.set(temp, currentPlayerIdx);
  }
  return players;
}
