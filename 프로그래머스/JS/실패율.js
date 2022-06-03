function sort(arr){
    
    for(let i=0; i<arr.length; i++){
        for(let j=i+1; j<arr.length; j++){
            if(arr[i][0] < arr[j][0]){
                let tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            else if(arr[i][0] === arr[j][0]){
                if(arr[i][1] > arr[j][1]){
                     let tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    
}
function solution(N, stages) {
    var answer = [];
    
    for(let i=1; i<=N; i++){
        let total = 0;
        let curr = 0;
        for(let j=0; j<stages.length; j++){
            if(stages[j] > i){
                total++;
            }
            else if(stages[j] === i) {
                total++;
                curr++;
            }
        }
        answer[i-1] = [(curr / total), i];  
    }
    
    sort(answer)
    
    let ret = []
    for(let i=0; i<answer.length; i++){
        ret.push(answer[i][1])
    }
    
    
    return ret;
}