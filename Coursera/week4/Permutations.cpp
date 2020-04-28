#include <bits/stdc++.h>

using namespace std;

int main()
{
    uint64_t n;
    vector<int> v;
    vector<vector<int>> u;
    cin >> n;

    for (uint64_t i = 1; i <= n; ++i)
        v.push_back(i);

    u.push_back(v);

    while (next_permutation(v.begin(), v.end()))
        u.push_back(v);

    for (uint64_t i = u.size(); i > 0; --i)
    {
        for (int j : u[i - 1])
            cout << j << ' ';

        cout << endl;
    }
}

