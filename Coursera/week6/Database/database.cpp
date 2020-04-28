#include "database.h"

void Database::Add(const Date &x, const string &y)
{
    if (Database::D[x].insert(y).second)
        Database::d[x].push_back(y);
}

void Database::Print(ostream &x) const
{
    for (auto i : Database::d)
        for (auto j : get<1>(i))
            x << get<0>(i).date << ' ' << j << endl;
}

int Database::RemoveIf(function<bool(const Date&, const string&)> f)
{
    int r = 0;
    vector<Date> v;

    for (auto i : Database::d)
    {
        r += Database::d[i.first].size();
        auto p = stable_partition(Database::d[i.first].begin(), Database::d[i.first].end(), [f,i](string &x){return !f(i.first, x);});

        for (auto j = p; j != Database::d[i.first].end(); ++j)
            Database::D[i.first].erase(Database::D[i.first].find(*j));

        Database::d[i.first].erase(p, Database::d[i.first].end());
        r -= Database::d[i.first].size();

        if (Database::d[i.first].size() == 0)
            v.push_back(i.first);
    }

    for (auto i : v)
        Database::d.erase(i),
        Database::D.erase(i);

    return r;
}

//template <typename T>
vector<string> Database::FindIf(function<bool(const Date&, const string&)> f) const
{
    vector<string> v;

    for (auto i : Database::d)
    //copy_if(i.second.begin(), i.second.end(), back_inserter(v), [f,i](const string &x){return f(i.first, x);});
        for (auto j : i.second)
            if (f(i.first, j))
                v.push_back(i.first.date + " " + j);
    /*for (auto i = v.begin(); i != v.end(); ++i)
        (*i) =  " " + i;*/

    return v;
}

string Database::Last(const Date &x) const
{
    auto i = Database::d.upper_bound(x);

    for (; i != Database::d.begin(); )
    {
        --i;
        if (i->first.date <= x.date && i->second.size() != 0)
            return i->first.date + " " + i->second.back();
    }

    return "No entries";
}

