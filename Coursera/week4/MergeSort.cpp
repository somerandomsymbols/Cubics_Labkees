#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin > 1)
    {
        vector<typename RandomIt::value_type> v(range_begin, range_end);
        MergeSort(v.begin(), v.begin() + v.size() / 2);
        MergeSort(v.begin() + v.size() / 2, v.end());
        merge(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2, v.end(), range_begin);
    }
}

int main()
{
    vector<int> u = {8,7,6,5,4,3,2,1};
    MergeSort(u.begin(),u.end());
    for(int i : u)
        cout << i;
}
