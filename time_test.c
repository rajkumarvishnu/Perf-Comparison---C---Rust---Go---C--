#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

int main()
{
    const int MAX_COUNT = 1000000; // Reduced from 100M to 1M for testing
    int i;
    int prime_count = 0; // Count of prime numbers found

    printf("Finding primes up to %d...\n", MAX_COUNT);

    // Record start time
    clock_t start_time = clock();

    // Loop from 2 to MAX_COUNT
    for (i = 2; i < MAX_COUNT; i++)
    {
        // Check if the number is prime
        if (is_prime(i))
        {
            prime_count++;
        }
    }

    // Record end time
    clock_t end_time = clock();

    // Calculate time taken in milliseconds
    double time_taken = (((double)(end_time - start_time)) / CLOCKS_PER_SEC) * 1000.0;

    printf("Finished checking primes up to %d\n", MAX_COUNT);
    printf("C - Time taken: %.5f milliseconds\n", time_taken);
    printf("Number of primes found: %d\n", prime_count);

    return 0;
}