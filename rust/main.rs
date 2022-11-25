// hello world
use std::slice::range;

fn fibonacci(n: i32) -> i32 {
  // return nth fibonacci number
  if n == 0 {
    return 0;
  } else if n == 1 {
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  } 
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
  // print first 10 fibonacci numbers
  for i in range(0, 10) {
    println!("fibonacci({}) = {}", i, fibonacci(i));
  }
}