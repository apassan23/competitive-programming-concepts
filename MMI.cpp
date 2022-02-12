#include <bits/stdc++.h>
using namespace std;

int binExp(int a, int b, const int &M)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a;
    cin >> a;
    // (A / B) mod M = (A * (B ^ -1)) mod M
    // We have to find B ^ -1
    const int M = 1e9 + 7;
    // Fermat's Theorem: A ^ M-1 = 1 mod M
    // Multiplying A ^ -1 on both sides
    // A ^ M-2 = (A ^ -1) mod M
    cout << binExp(a, M - 2, M);
}