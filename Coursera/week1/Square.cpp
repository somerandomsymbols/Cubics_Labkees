#include <bits/stdc++.h>
using namespace std;

template<typename T> T Sqr(T x);
template<typename T> vector<T> Sqr(vector<T> x);
template<typename T, typename Y> map<T,Y> Sqr(map<T,Y> x);
template<typename T, typename Y> pair<T,Y> Sqr(pair<T,Y> x);

template<typename T>
T Sqr(T x)
{
    return x*x;
}

template <typename T, typename Y>
pair<T,Y> Sqr(pair<T,Y> x)
{
    return pair<T,Y>(Sqr(get<0>(x)),Sqr(get<1>(x)));
}

template <typename T, typename Y>
map<T,Y> Sqr(map<T,Y> x)
{
    map<T,Y> y;

    for (pair<T,Y> i : x)
        y[get<0>(i)] = Sqr(get<1>(i));

    return y;
}

template <typename T>
vector<T> Sqr(vector<T> x)
{
    vector<T> y;

    for (T i : x)
        y.push_back(Sqr(i));

    return y;
}

int main()
{
    // Пример вызова функции
vector<int> v = {1, 2, 3};
cout << "vector:";
for (int x : Sqr(v)) {
  cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
cout << "map of pairs:" << endl;
for (const auto& x : Sqr(map_of_pairs)) {
  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
}
}
