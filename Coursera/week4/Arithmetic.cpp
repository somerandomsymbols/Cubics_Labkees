#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    uint64_t n;
    cin >> s >> n;
    deque<string> d;
    d.push_back(s);

    for (uint64_t i = 0; i < n; ++i)
    {
        string x, y;
        cin >> x >> y;
        d.push_front("(");
        d.push_back(") ");
        d.push_back(x);
        d.push_back(" ");
        d.push_back(y);
    }

    for (string i : d)
        cout << i;
}
