package main

import "fmt"

func main() {
	cq := circularQueue{
		items: [SIZE]int{},
		front: -1,
		rear:  -1,
	}
	cq.deQueue()
	cq.scan()

	cq.enQueue(1)
	cq.enQueue(2)
	cq.enQueue(3)
	cq.enQueue(4)
	cq.enQueue(5)
	cq.scan()

	cq.deQueue()
	cq.scan()

	cq.enQueue(5)
	cq.scan()
}

const SIZE = 4

type circularQueue struct {
	items [SIZE]int
	front int
	rear  int
}

func (q *circularQueue) isEmpty() bool {
	return q.rear == -1
}

func (q *circularQueue) isFull() bool {
	return (q.front == 0 && q.rear == SIZE-1) || (q.front == q.rear+1)
}

func (q *circularQueue) enQueue(element int) {
	if q.isFull() {
		fmt.Println("Queue is full")
		return
	}
	if q.isEmpty() {
		q.front += 1
	}
	q.rear = (q.rear + 1) % SIZE
	fmt.Println("Inserting element", element)
	q.items[q.rear] = element
}

func (q *circularQueue) deQueue() int {
	if q.isEmpty() {
		fmt.Println("Queue is empty")
		return -1
	}
	front := q.items[q.front]
	fmt.Println("Popping element", front)

	q.front = (q.front + 1) % SIZE
	if q.front == q.rear {
		q.front = -1
		q.rear = -1
	}

	return front
}

func (q *circularQueue) scan() {
	if q.isEmpty() {
		return
	}
	for i := q.front; i != q.rear; i = (i + 1) % SIZE {
		fmt.Printf("%d ", q.items[i])
	}
	fmt.Printf("%d", q.items[q.rear])
	fmt.Println()
}
