use std::collections::HashMap;
fn main() {
    for c in "你好呀".chars() {
        println!("{}", c);
    }
    let teams  = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];
    let scores: HashMap<_, _> = teams.iter().zip(initial_scores.iter()).collect();
}
