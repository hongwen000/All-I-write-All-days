use std::env;
use std::process;
extern crate rustgrep;
use rustgrep::Config;

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("{:?}", args);
    let config = Config::new(args).unwrap_or_else(|err| {
        println!("Problem parsing argument: {}", err);
        process::exit(1);
    });
    if let Err(e) = rustgrep::run(config) {
        println!("Error after parsing arguments: {}", e);
        process::exit(1);
    }
}
