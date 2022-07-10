function min(a, b) {
    return a > b ? b : a;
}

function solution(nums) {
    let arr = [];
    nums.forEach((num)=>{
        let isCommon = false;
       for(let i=0; i<arr.length; i++){
           if(arr[i]===num) isCommon = true;
       }
      isCommon ? '' : arr.push(num);
    })
    
    const arrLength = arr.length;
    const numLength = nums.length;
 
    return min(arrLength, numLength/2)
}

=================================

좀 더 간편한 풀이
function solutions(nums){
    const numLength = nums.length/2;
    const arr = [...new Set(nums)]; 

    return arr.length > numLength ? numLength : arr.length;
}
