use std::env;

fn insertion_sort(mut array: Vec<i32>) -> Vec<i32> {
    for j in 1..array.len() {
        let key = array[j];
        let mut i = j;
        while i > 0 && array[i - 1] > key {
            array[i] = array[i - 1];
            i -= 1;
        }
        array[i] = key;
    }

    array
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let numbers = &args[1..];
    let numbers: Vec<i32> = numbers.iter().map(|s| s.parse().unwrap()).collect();
    let numbers = insertion_sort(numbers);

    println!("{:?}", numbers);
}
