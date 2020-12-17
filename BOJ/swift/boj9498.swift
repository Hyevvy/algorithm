import Foundation
var inputNum=Int(readLine()!)!
if (inputNum>=90 && inputNum<=100){  print("A")
}
else if (inputNum>=80 && inputNum<=89){
    print("B")
}
else if(inputNum>=70 && inputNum<=79){
    print("C")
}
else if(inputNum>=60 && inputNum<=69){
    print("D")
}
else{
    print("F")
}
