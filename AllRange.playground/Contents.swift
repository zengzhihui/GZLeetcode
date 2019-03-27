import UIKit

/**
 * 全排列递归和非递归算法
 */

var tmpArray = [1, 2, 2]

func swapArray (array: inout [Int], k: Int, m: Int) {
    if k == m {
        return
    }
    let tmpInt = array[k]
    array[k] = array[m]
    array[m] = tmpInt
}

func printArray(array: [Int]) {
    for tmpInt in array {
        print(tmpInt, terminator:" ")
    }
    print("\n")
}

/// 从k开始反转
func reverseArray (array: inout [Int], k: Int) {
    var from = k
    var to = array.count - 1
    while from < to {
        swapArray(array: &array, k: from, m: to)
        from = from + 1
        to = to - 1
    }
}

/// 递归
func isNeedSwap(array: [Int], k: Int, index: Int) -> Bool {
    for tmpIdx in k..<index {
        if array[tmpIdx] == array[index] {
            return false
        }
    }
    return true
}

func allRange(array: inout [Int], k: Int, m: Int) {
    if k == m - 1 {
        for tmpInt in array {
            print(tmpInt, terminator:" ")
        }
        print("\n")
    } else {
        for index in k..<m {
            if !isNeedSwap(array: array, k: k, index: index) {
                continue
            }
            swapArray(array: &array, k: index, m: k)
            allRange(array: &array, k: k + 1, m: m)
            swapArray(array: &array, k: index, m: k)
        }
    }
}
print("==== 递归 ====")
allRange(array: &tmpArray, k:0, m: tmpArray.count)

/// 非递归
func hasNext(array: [Int]) -> Bool {
    for index in (1..<array.count).reversed() {
        if array[index - 1] < array[index] {
            return true
        }
    }
    return false
}

func noRecurveAllRange(array: inout [Int]) {
    array.sort { (value1, value2) -> Bool in
        if value1 < value2 {
            return true
        } else {
            return false
        }
    }
    printArray(array: array)
    while hasNext(array: array) {
        var cursor = 0
        for index in (1..<array.count).reversed() {
            if array[index - 1] < array[index] {
                cursor = index - 1
                break
            }
        }
        var bigger = cursor + 1
        for index in (cursor + 1 ..< array.count).reversed() {
            if array[index] > array[cursor] && array[index] < array[bigger] {
                bigger = index
            }
        }
        swapArray(array: &array, k: cursor, m: bigger)
        reverseArray(array: &array, k: cursor + 1)
        printArray(array: array)
    }
}

var tmpArray1 = [3, 2, 1, 4]
print("==== 非递归 ====")
noRecurveAllRange(array: &tmpArray1)

