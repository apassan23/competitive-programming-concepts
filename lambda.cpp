#include <iostream>
using namespace std;

int main()
{

    auto sum = [](int x, int y)
    { return x + y; };

    cout << sum(4, 6) << "\n";
    return 0;
}