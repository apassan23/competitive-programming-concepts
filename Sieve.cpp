#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, true);

int main()
{
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    // Time: O(N * log(log(N))
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            // Executes N/2 + N/3 + N/5 + ... ~ log(log(N))
            for (int j = 2 * i; j < N; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        cout << primes[i] << "\n";
    }
}