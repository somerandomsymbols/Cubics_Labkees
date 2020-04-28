#pragma once
#include <bits/stdc++.h>

using namespace std;

class Date
{
    public:
    string date;
    int year;
    int mounth;
    int day;

    Date();

    Date(const Date &x);

    Date (int x, int y, int z);
};

bool operator< (const Date &x, const Date &y);

ostream& operator<< (ostream &x, const Date &y);

Date ParseDate (istream &x);
