/*#include <vector>
#include <map>
#include <iostream>*/
#include <bits/stdc++.h>

using namespace std;

/*enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};*/

struct RC
{
    Region r;

    RC(Region x)
    {
        r = x;
    }

    bool operator<(const RC &a)
    {
        if (a.r.std_name != r.std_name)
            return a.r.std_name > r.std_name;
        if (a.r.parent_std_name != r.parent_std_name)
            return a.r.parent_std_name > r.parent_std_name;
        if (a.r.population != r.population)
            return a.r.population > r.population;

        return a.r.names > r.names;
    }

    bool operator==(const RC &a)
    {
        return r.std_name == a.r.std_name && r.parent_std_name == a.r.parent_std_name && r.population == a.r.population && r.names == a.r.names;
    }
};

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    if (regions.size() == 0)
        return 0;

    int m = 0;

    vector<RC> x;

    for (Region i : regions)
    {
        RC j = i;
        x.push_back(j);
    }

    sort(x.begin(),x.end());

    for (int i = 0; i < x.size();)
    {
        int n = 1,j;

        for (j = i + 1; j < x.size(); ++j)
            if (x[i] == x[j])
                ++n;
            else
                break;

        i = j;

        if (n > m)
            m = n;
    }

    return m;
}

int main() {
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;

  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;

  return 0;
}


