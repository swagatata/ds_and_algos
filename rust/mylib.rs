fn add(a: i64, b: i64) -> i64 {
	a+b
}

fn fibonacci_recursive(n: i64) -> i64 {
  if n <= 1 {
    1
  } else {
    fibonacci_recursive(n-1) + fibonacci_recursive(n-2)
  }
}

pub fn fibonacci(n: i32) -> u64 {
  // return nth fibonacci number
  let mut one: u64 = 1;
  let mut two: u64 = 1;

  for _i in 3..n {
    let temp = one + two;
    one = two;
    two = temp;
  }

  two
}