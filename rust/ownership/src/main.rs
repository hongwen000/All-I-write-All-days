/*
fn main() {
    let mut s = String::from("Hello");
    s.push_str(", world!");
    println!("{}", s);
}

fn tk_owner(s: &String) {
    println!("{}", s);
}
fn main() {
    let s = String::from("Hello");
    tk_owner(&s);
    println!("{}", s);
}
fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();
    for(i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}
fn main()
{

}
*/
fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();
    for(i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}

fn main() {
    let s = String::from("Two words");
    println!("{}", first_word(&s))
}