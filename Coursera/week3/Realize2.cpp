#include <bits/stdc++.h>

#include "phone_number.h"

using namespace std;

  /* Принимает строку в формате +XXX-YYY-ZZZZZZ
     Часть от '+' до первого '-' - это код страны.
     Часть между первым и вторым символами '-' - код города
     Всё, что идёт после второго символа '-' - местный номер.
     Код страны, код города и местный номер не должны быть пустыми.
     Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

     Примеры:
     * +7-495-111-22-33
     * +7-495-1112233
     * +323-22-460002
     * +1-2-coursera-cpp
     * 1-2-333 - некорректный номер - не начинается на '+'
     * +7-1233 - некорректный номер - есть только код страны и города
  */
PhoneNumber::PhoneNumber(const string &international_number)
{
    string s = international_number;

    if (s == "" || s[0] != '+')
        throw invalid_argument(s + "dick:1");

    int i = 1, city, local, l = s.length();

    while (i < l && s[i] != '-')
        ++i;

    if (i == l)
        throw invalid_argument(s + "dick:2");

    city = ++i;

    while (i < l && s[i] != '-')
        ++i;

    if (i == l)
        throw invalid_argument(s + "dick:3");

    local = ++i;

    if (local >= l)
        throw invalid_argument(s + "dick:4");

    if ((city - 2)*(local - city - 1)*(l - local + 1) == 0)
        throw invalid_argument(s + "dick:5");

    PhoneNumber::country_code_ = s.substr(1, city - 2);
    PhoneNumber::city_code_ = s.substr(city, local - city - 1);
    PhoneNumber::local_number_ = s.substr(local, l - local + 1);
}

string PhoneNumber::GetCountryCode() const
{
    return PhoneNumber::country_code_;
}

string PhoneNumber::GetCityCode() const
{
    return PhoneNumber::city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
    return PhoneNumber::local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return "+" + PhoneNumber::country_code_ + "-" + PhoneNumber::city_code_ + "-" + PhoneNumber::local_number_;
}
