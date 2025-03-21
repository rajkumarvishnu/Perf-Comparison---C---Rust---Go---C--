use std::time::Instant;

fn is_prime(n: i32) -> bool {
    if n <= 1 {
        return false;
    }
    if n <= 3 {
        return true;
    }
    if n % 2 == 0 || n % 3 == 0 {
        return false;
    }

    let mut i = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 {
            return false;
        }
        i += 6;
    }
    return true;
}

fn main() {
    const MAX_COUNT: i32 = 100000000;
    let mut prime_count: i32 = 0; // Count of prime numbers found

    println!("Finding primes up to {}...", MAX_COUNT);

    // Record start time
    let start_time = Instant::now();

    // Loop from 2 to MAX_COUNT
    for i in 2..MAX_COUNT {
        // Check if the number is prime
        if is_prime(i) {
            prime_count += 1;
        }
    }

    // Calculate time taken in milliseconds
    let time_taken = start_time.elapsed();
    let milliseconds = time_taken.as_secs_f64() * 1000.0;

    println!("Finished checking primes up to {}", MAX_COUNT);
    println!("Rust - Time taken: {:.5} milliseconds", milliseconds);
    println!("Number of primes found: {}", prime_count);
}
