#include <bits/stdc++.h>
#include "sum_reverse_sort.h"

using namespace std;

int Sum(int x, int y)
{
    return x + y;
}

string Reverse(string s)
{
    string x = "";

    for (int i = s.length() - 1; i >= 0; --i)
        x += s.substr(i,1);

    return x;
}
void Sort(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
}
