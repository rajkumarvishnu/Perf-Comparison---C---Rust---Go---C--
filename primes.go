package main

import (
	"fmt"
	"time"
)

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}

	i := 5
	for i*i <= n {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
		i += 6
	}
	return true
}

func main() {
	const maxCount = 1000000 // 1 million, matching other versions
	primeCount := 0

	fmt.Printf("Finding primes up to %d...\n", maxCount)

	// Record start time
	startTime := time.Now()

	// Loop from 2 to maxCount
	for i := 2; i < maxCount; i++ {
		if isPrime(i) {
			primeCount++
		}
	}

	// Calculate time taken in milliseconds
	timeTaken := time.Since(startTime).Milliseconds()

	fmt.Printf("Finished checking primes up to %d\n", maxCount)
	fmt.Printf("Go - Time taken: %d milliseconds\n", timeTaken)
	fmt.Printf("Number of primes found: %d\n", primeCount)
}