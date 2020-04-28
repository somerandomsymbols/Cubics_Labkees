#include "date.h"

Date::Date()
{
    Date::date = "0000-00-00";
    Date::year = Date::mounth = Date::day = 0;
}

Date::Date(const Date &x)
{
    Date::date = x.date;
    Date::year = x.year;
    Date::mounth = x.mounth;
    Date::day = x.day;
}

Date::Date (int x, int y, int z)
{
    Date::year = x;
    Date::mounth = y;
    Date::day = z;
    stringstream ss;
    ss << x / 1000 << x / 100 % 10 << x / 10 % 10 << x % 10 << '-' << y / 10 << y % 10 << '-' << z / 10 << z % 10;
    Date::date = ss.str();
}

bool operator< (const Date &x, const Date &y)
{
    vector<int> X = {x.year, x.mounth, x.day}, Y = {y.year, y.mounth, y.day};
    return X < Y;
}

ostream& operator<< (ostream &x, const Date &y)
{
    x << y.date;
    return x;
}

Date ParseDate (istream &x)
{
    string s;
    x >> s;
    int i = -1, year = 0, mounth = 0, day = 0;
    while (s[++i] != '-')
        year *= 10,
        year += s[i] - '0';

    while (s[++i] != '-')
        mounth *= 10,
        mounth += s[i] - '0';

    while (++i < s.length())
        day *= 10,
        day += s[i] - '0';

    return Date(year, mounth, day);
}

