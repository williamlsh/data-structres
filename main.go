package main

import "fmt"

func main() {
	var l List
	l.insertAtEnd(0)
	l.insertAtBeginning(1)
	l.insertAtBeginning(2)
	l.insertAtEnd(3)
	l.insertAtEnd(4)
	l.display()

	l.insertAfter(4, 5)
	l.display()

	l.deleteNode(3)
	l.display()
	fmt.Println(l.search(3))
	fmt.Println(l.search(4))

	l.reverse()
	l.display()

	l.sort()
	l.display()
}

type Node struct {
	data int
	next *Node
}

type List struct {
	head *Node
}

func (l *List) insertAtBeginning(data int) {
	var node Node
	node.data = data
	node.next = l.head
	l.head = &node
}

func (l *List) insertAtEnd(data int) {
	var node Node
	node.data = data
	node.next = nil

	if l.head == nil {
		l.head = &node
		return
	}

	temp := l.head
	for temp.next != nil {
		temp = temp.next
	}
	temp.next = &node
}

func (l *List) insertAfter(position, data int) {
	var node Node
	node.data = data

	temp := l.head
	for i := 2; i < position; i++ {
		if temp.next != nil {
			temp = temp.next
		}
	}
	node.next = temp.next
	temp.next = &node
}

func (l *List) deleteNode(key int) {
	var prev *Node
	temp := l.head
	// Find the key.
	for temp != nil {
		if temp.data == key {
			break
		}
		prev = temp
		temp = temp.next
	}
	// No key found in list.
	if temp == nil {
		return
	}
	// Key is found in list.
	prev.next = temp.next
}

func (l *List) search(key int) bool {
	temp := l.head
	for temp != nil {
		if temp.data == key {
			break
		}
		temp = temp.next
	}
	return temp != nil
}

func (l *List) reverse() {
	var prev *Node
	current := l.head
	var next *Node

	for current != nil {
		next = current.next
		current.next, prev, current = prev, current, next
	}
	l.head = prev
}

func (l *List) sort() {
	if l.head == nil {
		return
	}
	current := l.head
	for current != nil {
		index := current.next
		for index != nil {
			if current.data > index.data {
				current.data, index.data = index.data, current.data
			}
			index = index.next
		}
		current = current.next
	}
}

func (l *List) display() {
	p := l.head
	for p != nil {
		fmt.Printf("%d ", p.data)
		p = p.next
	}
	fmt.Println()
}
