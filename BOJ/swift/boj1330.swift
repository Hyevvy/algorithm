import Foundation
let inputNum=readLine()
if let num = inputNum {
    let array = num.components(separatedBy: " ")
    let num1 = Int(array[0])!
    let num2 = Int(array[1])!
    if num1<num2 {print("<")}
    else if num1 == num2 {print("==")}
    else if num1>num2 {print(">")}
}
