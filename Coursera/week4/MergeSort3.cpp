#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin > 1)
    {
        vector<typename RandomIt::value_type> v(range_begin, range_end);
        MergeSort(v.begin(), v.begin() + v.size() / 3),
        MergeSort(v.begin() + v.size() / 3, v.end() - v.size() / 3),
        MergeSort(v.end() - v.size() / 3, v.end());
        vector<typename RandomIt::value_type> u;
        merge(v.begin(), v.begin() + v.size() / 3, v.begin() + v.size() / 3, v.end() - v.size() / 3, back_inserter(u));
        merge(u.begin(), u.end(), v.end() - v.size() / 3, v.end(), range_begin);
    }
}

int main()
{
    vector<int> u = {9,8,7,6,5,4,3,2,1};
    MergeSort(u.begin(),u.end());
    for(int i : u)
        cout << i;
}

