#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &data)
{
    vector<int> nge(data.size());
    stack<int> st;

    for (int i = 0; i < data.size(); i++)
    {
        while (!st.empty() && (data[i] > data[st.top()]))
        {
            nge[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }

    return nge;
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);

    for (int &e : data)
    {
        cin >> e;
    }

    auto nge = NGE(data);

    for (int i = 0; i < nge.size(); i++)
    {
        cout << data[i] << " " << (nge[i] == -1 ? -1 : data[nge[i]]) << "\n";
    }
    return 0;
}