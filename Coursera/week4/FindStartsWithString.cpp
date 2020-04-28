#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix)
{
    RandomIt x = range_begin, y = range_end;

    while (x != y)
    {
        RandomIt z = x + (y - x) / 2;

        if ((*z).substr(0, prefix.length()) < prefix)
            x = z + 1;
        else
            y = z;
    }

    RandomIt a = x;
    y = range_end;

    while (x != y)
    {
        RandomIt z = x + (y - x) / 2;

        if ((*z).substr(0, prefix.length()) <= prefix)
            x = z + 1;
        else
            y = z;
    }

    return pair<RandomIt, RandomIt>(a,x);
}

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}
