// hello world
// import date
use std::time::SystemTime;
use date::Date;

struct Person {
    name: string,
    dob: date::Date,
}

fn test_format() {
  println!("hello, world");
  println!("hello, {}", "swagat");
  println!("hello, {name}", name="swagat");
  println!("hello, {} {} {}", "swagat", "rakhi", "vidhi");
  println!("hello, {name} {}", "sexy", name="swagat");

  let s = "love";
  println!("hello, {s} {}", "sexy"); 
  println!("hello, {s} {}", "sexy"); 
  println!("hello, {s} {:#?}", [1, 2]); 
  println!("hello, {s} {:04}", 100); 
  println!("hello, {1} {0:04}", 100, 2); 

  println!("hello, {s} {:#x}", 100); 
  println!("hello, {s} {:#010b}", 100); 
}

// main function
fn main() {
  // test_format();
  // for loop in range 1 to 10

  // testing fibonacci
  // for i in 1..100 {
  //   println!("fibonacci({}) = {}", i, mylib::fibonacci(i));
  // }

  // structs
  let s = Person {
    name: "swagat".to_string(),
    dob: date::Date {
      year: 1989,
      month: 12,
      day: 31,
    },
  };
}