package main

import "fmt"

func main() {
	arr := []int{100, -20, 2, 0, 12, -100, 98}
	fmt.Printf("%+v", selectionSort(arr, len(arr)))
}

func selectionSort(arr []int, size int) []int {
	for step := 0; step < size-1; step++ {
		min_idx := step
		for i := 1 + step; i < size; i++ {
			if arr[i] < arr[min_idx] {
				min_idx = i
			}
		}
		arr[min_idx], arr[step] = arr[step], arr[min_idx]
	}
	return arr
}
