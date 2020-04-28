#include <bits/stdc++.h>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{
    RandomIt x = range_begin, y = range_end;
    string s = "";
    s.push_back(prefix);

    while (x != y)
    {
        RandomIt z = x + (y - x) / 2;

        if ((*z).substr(0, 1) < s)
            x = z + 1;
        else
            y = z;
    }

    RandomIt a = x;
    y = range_end;

    while (x != y)
    {
        RandomIt z = x + (y - x) / 2;

        if ((*z).substr(0, 1) <= s)
            x = z + 1;
        else
            y = z;
    }

    return pair<RandomIt, RandomIt>(a,x);
}

int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;

  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;

  return 0;
}
