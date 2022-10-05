package main

import "fmt"

func main() {
	data := []int{-2, 45, 0, 11, -9}
	fmt.Printf("list: %+v", bubbleSort(data))
}

func bubbleSort(list []int) []int {
	for step := 0; step < len(list)-1; step++ {
		swapped := false
		for i := 0; i < len(list)-step-1; i++ {
			if list[i] > list[i+1] {
				list[i], list[i+1] = list[i+1], list[i]
				swapped = true
			}
		}
		if !swapped {
			break
		}
	}
	return list
}
