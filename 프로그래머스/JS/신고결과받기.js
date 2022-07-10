function getIdx(id_list, name){
    for(let i=0; i<id_list.length; i++){
        if(id_list[i] === name) return i;
    }
}
function solution(id_list, report, k) {
    const answer = new Array(id_list.length).fill(0);
    
    const reported = Array.from(Array(id_list.length), () => new Set());
 
    for(let i=0; i<report.length; i++){
        const reportList = report[i].split(' ');
        reported[getIdx(id_list, reportList[1])].add(reportList[0]);
    }
    
    for(let i=0; i<reported.length; i++){
        const tempArr = Array.from(reported[i])
        if(tempArr.length >= k){
            for(let j=0; j<tempArr.length; j++){
                answer[getIdx(id_list,tempArr[j])]++;
            }
        }
    }
    
    return answer;
}