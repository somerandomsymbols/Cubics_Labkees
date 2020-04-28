#include <bits/stdc++.h>

using namespace std;

template <typename T, typename Y>
Y& GetRefStrict(map<T,Y> &x, T y)
{
    if (x.find(y) == x.end())
        throw runtime_error("");

    return x[y];
}

int main()
{
    map<int, string> m = {{0, "value"}};
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl; // выведет newvalue
}
