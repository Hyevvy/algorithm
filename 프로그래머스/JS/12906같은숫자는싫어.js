function solution(arr)
{
    let answer = [arr[0]];
    let size = 0;
    for(let i=1; i<arr.length; i++){
        if(arr[i]===answer[size]) {
          continue;
        }
        else{
            answer.push(arr[i]);
            size++;
        }
    }
    return answer;
}


// 아래 방법으로 다시
function solution(arr)
{
    let answer = [arr[0]];
    let size = 0;
    for(let i=1; i<arr.length; i++){
        if(arr[i]!=answer[size]) {
            answer.push(arr[i]);
            size++;
        }
    }
    return answer;
}

//
function solution(arr)
{
    let answer = [arr[0]];
    let size = answer.length-1;
    for(let i=1; i<arr.length; i++){
        if(arr[i]!=answer[size]) {
            answer.push(arr[i]);
            size++;
        }
    }
    return answer;
}
