import Foundation

var inputNum=Int(readLine()!)!

for i in 0 ..< inputNum {
    //var k = i-1
    for var k in 0 ..< i+1 {
        print("*",terminator:"")
        k=k+1
    }
   print()
}
