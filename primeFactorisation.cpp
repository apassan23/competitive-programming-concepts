#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector<int> isPrime(N, true);
// vectors for lowest prime and highest prime
vector<int> lp(N), hp(N);

int main()
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

    vector<int> prime_factors;
    int num;
    cin >> num;

    while (num > 1)
    {
        int prime_factor = lp[num];
        while (num % prime_factor == 0)
        {
            num /= prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }

    for (auto &pf : prime_factors)
        cout << pf << " ";

    return 0;
}