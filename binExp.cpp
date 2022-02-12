#include <bits/stdc++.h>
using namespace std;

class BinaryExp
{
private:
    static const int M = 1e9 + 7;

public:
    // Complexity: O(log(b))
    static int pow(int a, int b)
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
};

class LargeBinaryExp
{
private:
    static const long long M = 1e18 + 7;

public:
    // Complexity: O(log^2(b))
    static long long binMultiply(long long a, long long b)
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

    static long long pow(long long a, long long b)
    {
        long long ans = 1;
        while (b)
        {
            if (b & 1)
                ans = binMultiply(a, ans);
            a = binMultiply(a, a);
            b >>= 1;
        }

        return ans;
    }
};

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << "Normal: " << BinaryExp::pow(a, b) << "\n"; // O(log(b))
    cout << "Large: " << LargeBinaryExp::pow(a, b);     // O(log^2(b))
    return 0;
}