#include <iostream>

using namespace std;

int main()
{
    uint64_t n,r,s=0,a,b,c;
    cin >> n >> r;

    for (int i = 0; i < n; ++i)
        cin >> a >> b >> c,
        s += a*b*c*r;

    cout << s << endl;
    return 0;
}
