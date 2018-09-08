use std::iter::*;
fn abs(a: f32) -> f32
{
    if a > 0.0 {
        a
    }
    else{
        -a
    }
}
fn main() {
    let pts = vec![
        vec![7.4, 0.70],
        vec![7.8, 0.88],
        vec![7.8, 0.76],
        vec![11.2, 0.28],
    ];
    let pre = vec![7.4, 0.70]; 
    
    let L1_Distant = |vec: &Vec<f32>| -> f32{
        let r = pre.iter().zip(vec.iter());
        r.map(|(&a, &b)| abs(a - b)).sum()
    };

    let sum_of_squares = pts
                        .iter()
                        .map(|vec: &Vec<f32>| L1_Distant(vec));
    for i in sum_of_squares {
        println!("{}", i);
    }
}
