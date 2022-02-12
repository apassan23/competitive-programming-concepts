#include <bits/stdc++.h>
using namespace std;

bool isSet(const int &num, const int &i)
{
    if (i > 31)
        return false;

    return (num & (1 << i));
}

int setBit(const int &num, const int &i)
{
    return (num | (1 << i));
}

int unSetBit(const int &num, const int &i)
{
    // ~ inverts all the 0s and 1s
    return (num & ~(1 << i));
}

int toggleBit(const int &num, const int &i)
{
    return (num ^ (1 << i));
}

void printBinary(const int &num)
{
    // equivalent to checking if the ith bit
    // is set in num
    for (int i = 10; i >= 0; i--)
        cout << isSet(num, i);
    cout << "\n";
}

int main()
{
    printBinary(0b101100);
    printBinary(setBit(0b101100, 1));
    printBinary(unSetBit(0b101100, 3));
    printBinary(toggleBit(0b101100, 4));
    printBinary(toggleBit(toggleBit(0b101100, 4), 4));
    // count number of set bits
    cout << __builtin_popcount(0b111101);
    return 0;
}