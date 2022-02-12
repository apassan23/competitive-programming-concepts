#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> divisors[N];

int main()
{
    divisors[0].push_back(0);
    divisors[1].push_back(1);

    // O(N * log(N))
    for (int i = 2; i < N; i++)
    {
        // executes N/2 + N/3 + N/4 + ... ~ log(N)
        for (int j = i; j < N; j += i)
            divisors[j].push_back(i);
    }

    for (int i = 1; i <= 20; i++)
    {
        for (auto &div : divisors[i])
            cout << div << " ";
        cout << "\n";
    }

    return 0;
}