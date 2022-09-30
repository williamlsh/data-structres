#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_stack() {
        let mut stack = Stack {
            items: [0; MAX],
            top: None,
        };
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        assert_eq!(
            Stack {
                items: [1, 2, 3],
                top: Some(2),
            },
            stack
        );

        stack.pop();
        assert_eq!(
            Stack {
                items: [1, 2, 3],
                top: Some(1),
            },
            stack
        );

        stack.push(4);
        assert_eq!(
            Stack {
                items: [1, 2, 4],
                top: Some(2),
            },
            stack
        );
    }
}

const MAX: usize = 3;

#[derive(Debug, PartialEq)]
struct Stack<const N: usize> {
    items: [usize; N],
    top: Option<usize>,
}

impl<const N: usize> Stack<N> {
    fn is_full(&self) -> bool {
        if let Some(top) = self.top {
            top == self.items.len() - 1
        } else {
            false
        }
    }

    fn is_empty(&self) -> bool {
        self.top.is_none()
    }

    fn peek(&self) -> Option<usize> {
        self.top.map(|top| self.items[top])
    }

    fn push(&mut self, item: usize) {
        if self.is_full() {
            println!("Stack is full");
        } else {
            match self.top.as_mut() {
                Some(top) => {
                    *top += 1;

                    println!("Pushing item: {}", item);
                    self.items[*top] = item;
                }
                None => {
                    self.top = Some(0);

                    println!("Pushing item: {}", item);
                    self.items[0] = item;
                }
            }
        }
    }

    fn pop(&mut self) {
        match self.top.as_mut() {
            Some(top) => {
                let item = self.items[*top];
                println!("Popping item: {}", item);

                *top -= 1;
            }
            None => println!("Stack is empty"),
        }
    }
}
