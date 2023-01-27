var divisors = [];
function isInDivisors(num){
    for(let i=0; i<divisors.length; i++){
        if(divisors[i] === num) return true;
    }
    return false;
}

function solution(n) {
    var answer = 0;
    var isSquareNumber = false;

    for(let i = 1; i<=n; i++){
        if(n % i === 0) {
            if(isInDivisors(i)){
                break;
            }
            answer++;
            divisors.push(i); // 나누는 수와
            divisors.push(n/i); // 그 몫을 배열에 넣는다
            
            if(i === n / i){
                isSquareNumber = true;
            }
        }
    }
    if(isSquareNumber) return answer * 2 - 1;
    return answer * 2;
}

