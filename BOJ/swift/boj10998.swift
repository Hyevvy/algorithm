import Foundation
let a=readLine()
if let line = a{
    let array = line.components(separatedBy: " ")
    print(Int(array[0])!*Int(array[1])!)
}
