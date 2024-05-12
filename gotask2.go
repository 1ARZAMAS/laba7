package main

import (
	"fmt"
	"math"
)

func inverse(S string) string {
	inversed := ""
	for _, c := range S {
		if c == '0' {
			inversed += "1"
		} else {
			inversed += "0"
		}
	}
	return inversed
}

func reverse(S string) string {
	runes := []rune(S)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func recursion(n int) string {
	if n == 1 {
		return "0"
	}
	prevSeq := recursion(n - 1)
	return prevSeq + "1" + reverse(inverse(prevSeq))
}

func main() {
	var n, k int
	fmt.Print("Введите число n, 1 <= n <= 20: ")
	fmt.Scan(&n)
	for n <= 0 || n > 20 {
		fmt.Print("\nВведено неверное число n, попробуйте еще раз: ")
		fmt.Scan(&n)
	}
	fmt.Print("\nВведите число k, 1 <= k <= 2^n - 1: ")
	fmt.Scan(&k)
	for k <= 0 || k > int(math.Pow(2, float64(n))-1) {
		fmt.Print("\nВведено неверное число k, попробуйте еще раз: ")
		fmt.Scan(&k)
	}
	result := recursion(n)
	fmt.Println(string(result[k]))
}
