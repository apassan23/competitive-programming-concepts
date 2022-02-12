#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> dp(N, -1);

// TOP DOWN APPROACH
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    // memoise
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << "\n";
    return 0;
}