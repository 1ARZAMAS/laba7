package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

func buildSequenceRecursive(arr []int, lastNumber int) []int {
	longestSequence := []int{} // здесь будем хранить самую длинную последовательность
	for i := 0; i < len(arr); i++ {
		if lastNumber == -1 || strconv.Itoa(lastNumber)[len(strconv.Itoa(lastNumber))-1] == strconv.Itoa(arr[i])[0] {
			remaining := make([]int, len(arr))
			copy(remaining, arr)
			remaining = append(remaining[:i], remaining[i+1:]...)
			nextSequence := buildSequenceRecursive(remaining, arr[i])
			if len(nextSequence) > len(longestSequence) {
				longestSequence = nextSequence
			}
		}
	}
	if lastNumber != -1 {
		longestSequence = append([]int{lastNumber}, longestSequence...)
	}
	return longestSequence
}

func main() {
	rand.Seed(time.Now().UnixNano())

	n := 25
	arr := make([]int, n)
	for i := range arr {
		arr[i] = rand.Intn(1000) + 1
	}

	sequence := buildSequenceRecursive(arr, -1)
	fmt.Println("\nСамая длинная последовательность:")
	fmt.Println(sequence)
}
