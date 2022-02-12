#include <bits/stdc++.h>
using namespace std;

class ETF
{
public:
    static long long binMultiply(long long a, long long b, const int &M)
    {
        long long ans = 0;
        while (b)
        {
            if (b & 1)
                ans = (ans + a) % M;
            a = (a + a) % M;
            b >>= 1;
        }

        return ans;
    }

    static long long pow(long long a, long long b, const int &M)
    {
        long long ans = 1;
        while (b)
        {
            if (b & 1)
                ans = binMultiply(a, ans, M);
            a = binMultiply(a, a, M);
            b >>= 1;
        }

        return ans;
    }
};

int main()
{
    // 50 ^ 64 ^ 32
    const int M = 1e18 + 7;
    cout << ETF::pow(50, ETF::pow(64, 32, M - 1), M);
    return 0;
}
