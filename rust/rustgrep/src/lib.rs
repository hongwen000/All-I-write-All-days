
use std::error::Error;
use std::fs::File;
use std::io::prelude::*;
pub struct Config {
    query: String,
    filen: String,
}
impl Config {
    pub fn new(args: Vec<String>) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("Not enough arguments");
        }
        let query = args[1].clone();
        let filen = args[2].clone();
        Ok(Config{query, filen})
    }
}
pub fn run(config: Config) -> Result<(), Box<Error>>{
    let mut f = File::open(config.filen)?;
    let mut contents = String::new();
    f.read_to_string(&mut contents)?;
    for line in search(&config.query, &contents) {
        println!("{}", line);
    }
    Ok(())
}
pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let mut ret = Vec::new();
    for line in contents.lines() {
        if line.contains(query) {
            ret.push(line);
        }
    }
    ret
}
#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn one_result() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";
        let ret = vec!["safe, fast, productive."];
        assert_eq!(ret, search(query, contents));
    }
}