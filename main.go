package main

import "fmt"

func main() {
	s := new(stack)
	s.top = -1

	s.push(1)
	s.push(2)
	s.push(3)
	s.push(4)
	fmt.Printf("stack: %+v\n", s)

	s.pop()
	fmt.Printf("stack: %+v\n", s)

	s.push(4)
	fmt.Printf("stack: %+v\n", s)

}

const MAX = 3

type stack struct {
	items [MAX]int
	top   int
}

func (s *stack) isFull() bool {
	return s.top == MAX-1
}

func (s *stack) isEmpty() bool {
	return s.top == -1
}

func (s *stack) peek() int {
	return s.items[s.top]
}

func (s *stack) push(item int) {
	if s.isFull() {
		fmt.Println("Stack is full.")
		return
	}
	fmt.Println("Pushing", item)

	s.top += 1
	s.items[s.top] = item
}

func (s *stack) pop() int {
	if s.isEmpty() {
		fmt.Println("Stack is empty.")
		return -1
	}

	top := s.top
	s.top -= 1

	item := s.items[top]
	fmt.Println("Popping", item)

	return item
}
