function solution(array) {
  let arr = new Map();

  for (let i = 0; i < array.length; i++) {
    arr.set(array[i], (arr.get(array[i]) || 0) + 1);
  }

  arr = [...arr].sort((a, b) => b[1] - a[1]);

  if (arr.length === 1) return arr[0][0];
  else if (arr[0][1] === arr[1][1]) return -1;

  return arr[0][0];
}
