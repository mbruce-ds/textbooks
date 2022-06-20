use std::env;

fn insertion_sort(mut array: Vec<i32>) -> Vec<i32> {
    let array_len = array.len();
    for j in 1..array_len-1 {
        let mut current_min = array[j];
        let stored_val = array[j];
        let mut stored_index = j;
        
        for i in j+1..array_len {
            if array[i] < current_min {
                current_min = array[i];
                stored_index = i;
            }
        } 

        array[j] = current_min;
        array[stored_index] = stored_val;
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
