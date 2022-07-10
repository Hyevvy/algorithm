function solution(seoul) {
    var answer = '';
    var index=0;
   // var seoulElement = seoul.split(',');
    for(var i in seoul){
        if(seoul[i]==="Kim") index=i;
    }
    answer="김서방은 "+index+"에 있다";
    return answer;
}