#include <iostream>
#include <vector>

using namespace std;

// Function to generate a list of prime numbers up to a given limit using the Sieve of Eratosthenes algorithm
vector<int> generatePrimes(int limit) {
    // Create a boolean vector to mark whether each number is prime or not
    vector<bool> isPrime(limit + 1, true);
    // Vector to store the prime numbers
    vector<int> primes;

    // Apply the Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            // Mark all multiples of i as not prime
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Add the prime numbers to the primes vector
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

// Function to display the list of prime numbers
void displayPrimes(const vector<int>& primes) {
    cout << "List of Prime Numbers: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
}

int main() {
    // Prompt the user to enter the limit for prime numbers
    cout << "Enter the limit for prime numbers: ";
    int limit;
    cin >> limit;

    // Check if the limit is less than 2
    if (limit < 2) {
        cout << "There are no prime numbers within the specified limit." << endl;
        return 0;
    }

    // Generate the list of prime numbers up to the specified limit
    vector<int> primeList = generatePrimes(limit);
    // Display the list of prime numbers
    displayPrimes(primeList);

    return 0;
}