function isHit(cacheSize, cache, target){
  for(let i=0; i<cache.length; i++){
      if(cache[i].toUpperCase() === target.toUpperCase()) {
          //target을 맨 앞으로 두기
          cache.splice(i,1)
          cache.unshift(target)
          return 1;
      }
  }
  
       //없으면 하나 빼고 캐시에 저장해야함 
  if(cacheSize === cache.length) {
      cache.pop();
  }
  
  cache.unshift(target);
  
  return 5;
}
function solution(cacheSize, cities) {
  var answer = 0; // 총 실행시간
  let cache = [];
 
  if(cacheSize === 0) return cities.length * 5;
  for(let i=0; i<cities.length; i++){
      answer += isHit(cacheSize, cache, cities[i])
  }
  
  return answer;
}