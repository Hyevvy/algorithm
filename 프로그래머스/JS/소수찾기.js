function solution(n) {
    var primeNum = [];
    var answer = 0;//소수의 개수
    for (let i = 2; i <= n; i++) {
        let state = 0; //소수임 
        if (i == 2) { answer++; continue; }
        for (let j = 2; j * j <= i; j++) {
            if (i % j == 0) { state = 1; break; }
        }
        if (state == 0) { answer++; }
    }
    return answer;
}