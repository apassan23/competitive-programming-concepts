#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int N = 1e6 + 7;
vector<int> isPrime(N, true);
// vectors for lowest prime and highest prime
vector<int> lp(N), hp(N);

void preComputation()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
        if (isPrime[i])
        {
            hp[i] = lp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (!lp[j])
                    lp[j] = i;
            }
        }
}
void testAlgo1()
{
    for (int n = 2; n < N; n++)
    {
        vector<int> prime_factors;
        int num = n;
        while (num > 1)
        {
            int prime_factor = hp[num];
            while (num % prime_factor == 0)
            {
                num /= prime_factor;
                prime_factors.push_back(prime_factor);
            }
        }
    }
}

void testAlgo2()
{
}

int main()
{
    preComputation();
    auto start = high_resolution_clock::now();
    testAlgo1();
    auto end = high_resolution_clock::now();
    cout << "Time for Algo1: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    testAlgo2();
    end = high_resolution_clock::now();

    cout << "Time for Algo2: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    return 0;
}