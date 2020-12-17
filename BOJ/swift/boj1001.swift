import Foundation

var a = readLine()
if let printed = a {
    let array = printed.components(separatedBy:" ")
    let a=Int(array[0])!
    let b=Int(array[1])!
    print(a-b)
}


