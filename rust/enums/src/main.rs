/*
enum IpAddrKind {
    V4,
    V6,
}
fn route(ip_type: IpAddrKind) {

}
//struct IpAddr {
//    kind: IpAddrKind,
//    addr: String,
//}
enum IpAddr {
    V4(String),
    V6(String)
}
fn main() {
    let four = IpAddr::V4(String::from("127.0.0.1"));
    let six  = IpAddr::V6(String::from("::1"));
}


enum Message {
    Quit,
    Move {x: i32, y: i32},
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {

    }
}


fn main()
{
    let m = Message::Write(String::from("Hello"));
    m.call();
    let some_num = Some(5);
    let some_str = Some("A string");
    let absent_num: Option<i32> = None;
}

#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
}
fn main() {
    enum Coin {
        Penny,
        Nickel,
        Dime,
        Quarter(UsState),
    }

    fn value_in_cents(coin: Coin) -> u32 {
        match coin {
            Coin::Penny => 1,
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter(state) => {
                println!("State quater from {:?}!", state);
                25
            }
        }
    }
    value_in_cents(Coin::Quarter(UsState::Alabama));
}

#![allow(unused_variables)]
fn main() {
let some_u8_value = Some(0u8);
if let Some(3) = some_u8_value {
    println!("Three");
}
}
*/
fn main()
{
    #[derive(Debug)]
    enum UsState {
        Alabama,
        Alaska,
    }
    enum Coin {
        Penny,
        Nickel,
        Dime,
        Quarter(UsState),
    }
    let mut cnt = 0;
    let coin = Coin::Quarter(UsState::Alabama);
    let coin = Coin::Penny;
    if let Coin::Quarter(state) = coin {
        println!("State quater from {:?}!", state);
    } else {
        cnt += 1;
    }
    println!("{}", cnt);
}