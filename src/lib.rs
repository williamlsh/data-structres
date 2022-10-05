#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_bubble_sort() {
        let mut data = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1];
        bubble_sort(&mut data);
        dbg!(data);
    }
}

fn bubble_sort<T: Ord>(list: &mut [T]) {
    for step in 0..list.len() - 1 {
        let mut swapped = false;
        for i in 0..list.len() - step - 1 {
            if list[i] > list[i + 1] {
                list.swap(i, i + 1);
                swapped = true;
            }
        }
        if !swapped {
            break;
        }
    }
}
