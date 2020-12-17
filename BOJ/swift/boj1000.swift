import Foundation
let line=readLine()!
let lineArr=line.components(separatedBy: " ")
let a=Int(lineArr[0])!
let b=Int(lineArr[1])!
print(a+b)


//
import Foundation 이란 개발에 꼭 필요하고 기본이 되는 것들이 포함되어이으며, 문자 스트링 숫자 등 기본 객체와 컬랙션 딕셔너리 세트등 기본 기능이 들어있다.

⭐️ swift로 입력받기 -> readLine() 을 사용한다
단 결과가 Optional이라 강제 언래핑을 해줘야한다. 그치만 그것보다는 옵셔널 정리를 사용해서 nil체크를 해주는 것이 좋다.

ex) let a=readLIne()
if let printed = a{ // printed는 Optional타입이 아니다. String 타입이다.
print(printed)
}

if let printed = a{
var array=printed.components(separatedBy: " ")
}
//입력을 받은 이후 seperatedBy(" ")에 의해 " "을 기준으로 나뉘게 되고, components를 사용하면 배열이 되어 배열 타입에 저장할 수 있다.
