#include <iostream>
using namespace std;

double multiply(const double &x, const int &n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= x;

    return ans;
}

double nthRoot(const double &x, const int &n, const double &eps)
{
    double hi = x, lo = 1;
    while (hi - lo > eps)
    {
        double mid = (lo + hi) / 2;

        if (multiply(mid, n) < x)
            lo = mid;

        else
            hi = mid;
    }

    return lo;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;

    cout << nthRoot(x, n, 1e-6);

    return 0;
}