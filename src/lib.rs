#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_selection_sort() {
        let mut arr = [1000, -10, 4, 2, 90, 0, 20, -9];
        selection_sort(&mut arr);
        dbg!(arr);
    }
}

fn selection_sort<T: Ord>(arr: &mut [T]) {
    for step in 0..arr.len() - 1 {
        let mut min_idx = step;
        for i in 1 + step..arr.len() {
            if arr[i] < arr[min_idx] {
                min_idx = i;
            }
        }
        arr.swap(step, min_idx);
    }
}
