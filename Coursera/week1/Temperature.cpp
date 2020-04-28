#include <iostream>

using namespace std;

int main()
{
    int64_t u = 0,n,t=0;
    int *a;
    cin >> n;
    a = new int[n];

    for (int i = 0; i < n; ++i)
        cin >> *(a+i),
        u += *(a+i);

    u /= n;

    for (int i = 0; i < n; ++i)
        if (*(a+i) > u)
            ++t;

    cout << t << endl;

    for (int i = 0; i < n; ++i)
        if (*(a+i) > u)
            cout << i << ' ';

    cout << endl;
    return 0;
}
