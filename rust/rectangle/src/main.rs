/*
fn area(w: u32, h: u32) -> u32 {
    w * h
}
fn main() {
    let w = 30;
    let h = 50;
    println!("{}", area(w, h));
}

*/
#[derive(Debug)]
struct Rect {
    w: u32,
    h: u32,
}
impl Rect {
    fn area(&self) -> u32 {
        self.w * self.h
    }
}
fn main() {
    let rect1 = Rect{w: 30, h: 50};
    println!("{:#?}", rect1.area());
}