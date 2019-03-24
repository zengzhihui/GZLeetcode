import UIKit

var tmpArray = [1, 2, 3, 4]

func swapArray (array: inout [Int], k: Int, m: Int) {
    if k == m {
        return
    }
    let tmpInt = array[k]
    array[k] = array[m]
    array[m] = tmpInt
}

func allRange(array: inout [Int], k: Int, m: Int) {
    if k == m - 1 {
        for tmpInt in array {
            print(tmpInt, terminator:" ")
        }
        print("\n")
    } else {
        for index in k..<m {
            swapArray(array: &array, k: k, m: index)
            allRange(array: &array, k: k + 1, m: m)
            swapArray(array: &array, k: k, m: index)
        }
    }
}
allRange(array: &tmpArray, k:0, m: 4)
