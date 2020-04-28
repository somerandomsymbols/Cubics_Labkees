#pragma once
#include "date.h"

class Database
{
    public:
    map<Date, vector<string>> d;
    map<Date, set<string>> D;

    void Add(const Date &x, const string &y);

    void Print(ostream &x) const;

    int RemoveIf(function<bool(const Date&, const string&)> f);

    //template <typename T>
    vector<string> FindIf(function<bool(const Date&, const string&)> f) const;

    string Last(const Date &x) const;
};
