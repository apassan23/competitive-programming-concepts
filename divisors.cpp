#include <bits/stdc++.h>
using namespace std;

// Time = O(N)
void bruteForce(int &x)
{
    for (int i = 1; i <= x; i++)
        if (x % i == 0)
            cout << i << "\n";
}

// Time = O(sqrt(N))
void divSqrt(int &x)
{
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            cout << i << "\n";
            if (x / i != i)
                cout << x / i << "\n";
        }
    }
}

int main()
{
    int x;
    cin >> x;
    divSqrt(x);
}