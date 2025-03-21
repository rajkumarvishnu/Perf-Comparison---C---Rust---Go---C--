#include <iostream>
#include <chrono>
#include <cmath>

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
    int prime_count = 0;           // Count of prime numbers found

    std::cout << "Finding primes up to " << MAX_COUNT << "...\n";

    // Record start time using high resolution clock
    auto start_time = std::chrono::high_resolution_clock::now();

    // Loop from 2 to MAX_COUNT
    for (int i = 2; i < MAX_COUNT; i++)
    {
        // Check if the number is prime
        if (is_prime(i))
        {
            prime_count++;
        }
    }

    // Record end time
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate time taken in milliseconds
    auto time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    double ms_time = static_cast<double>(time_taken);

    std::cout << "Finished checking primes up to " << MAX_COUNT << '\n';
    std::cout << "C++ - Time taken: " << ms_time << " milliseconds\n";
    std::cout << "Number of primes found: " << prime_count << '\n';

    return 0;
}