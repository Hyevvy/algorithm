import Foundation
var myArraySize=Int(readLine()!)!

var myArray:[Int] = []
myArray = readLine()!.split(separator: " ").map { Int($0)!}

var min = myArray[0]
for i in 1..<myArraySize {
    if( myArray[i]<min) { min = myArray[i] }
}
var max = myArray[0]
for i in 1..<myArraySize {
    if(myArray[i]>max) { max = myArray[i] }
}
print(min, max)
//myArray.sort()
//print(myArray[0], myArray[myArraySize-1])
