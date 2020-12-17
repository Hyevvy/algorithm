import Foundation
var firstNum=Int(readLine()!)!
var secondNum=Int(readLine()!)!

print(firstNum*(secondNum%10))
print(firstNum*((secondNum%100)/10))
print(firstNum*(secondNum/100))
print(firstNum*secondNum)
