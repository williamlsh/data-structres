#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_circular_queue() {
        let mut cq = CircularQueue {
            items: [0; SIZE],
            front: None,
            rear: None,
        };
        cq.dequeue();
        assert!(!cq.is_full());

        cq.enqueue(1);
        cq.enqueue(2);
        cq.enqueue(3);
        cq.enqueue(4);
        cq.enqueue(5);
        cq.scan();
        assert_eq!(
            CircularQueue {
                items: [1, 2, 3, 4],
                front: Some(0),
                rear: Some(3),
            },
            cq
        );

        cq.dequeue();
        cq.scan();
        assert_eq!(
            CircularQueue {
                items: [1, 2, 3, 4],
                front: Some(1),
                rear: Some(3),
            },
            cq
        );

        cq.enqueue(5);
        cq.scan();
        assert_eq!(
            CircularQueue {
                items: [5, 2, 3, 4],
                front: Some(1),
                rear: Some(0),
            },
            cq
        );
    }
}

const SIZE: usize = 4;

#[derive(Debug, PartialEq)]
struct CircularQueue<const N: usize> {
    items: [usize; N],
    front: Option<usize>,
    rear: Option<usize>,
}

impl<const N: usize> CircularQueue<N> {
    fn is_empty(&self) -> bool {
        self.rear.is_none()
    }

    fn is_full(&self) -> bool {
        if self.is_empty() {
            return false;
        }
        (self.rear == Some(SIZE - 1) && self.front == Some(0))
            || (self.rear.map(|n| n + 1) == self.front)
    }

    fn enqueue(&mut self, element: usize) {
        if self.is_full() {
            println!("Queue is full");
            return;
        }
        println!("Inserting {}", element);
        match self.rear.as_mut() {
            Some(rear) => {
                *rear = (*rear + 1) % SIZE;
            }
            None => {
                self.front = Some(0);
                self.rear = Some(0);
            }
        }
        self.items[self.rear.unwrap()] = element;
    }

    fn dequeue(&mut self) -> Option<usize> {
        if self.is_empty() {
            println!("Queue is empty");
            return None;
        }
        let front = self.items[self.front.unwrap()];
        println!("Popping {}", front);

        self.front = self.front.map(|front| (front + 1) % SIZE);
        if self.front == self.rear {
            self.front = None;
            self.rear = None;
        }

        Some(front)
    }

    fn scan(&self) {
        if self.is_empty() {
            return;
        }
        let mut i = self.front.unwrap();
        loop {
            print!("{} ", self.items[i]);
            if i == self.rear.unwrap() {
                break;
            }
            i = (i + 1) % SIZE;
        }
        println!()
    }
}
