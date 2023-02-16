#include "Date.h"

Date::Date(int year, int month, int day)
    : _year(year)
    , _month(month)
    , _day(day)
{
    if (year < 1
        || _month < 1 || _month > 12
        || _day < 1 || _day > getMonthday())
        cerr << "日期非法" << endl;
}

Date::~Date()
{}

Date::Date(const Date& d)
{
    if (this != &d)
    {
        _year  = d._year;
        _month = d._month;
        _day   = d._day;
    }
}

Date& Date::operator=(const Date& d)
{
    if (this != &d)
    {
        _year  = d._year;
        _month = d._month;
        _day   = d._day;
    }
    return *this;
}

int Date::getMonthday()
{
    static int monthDay[]
        = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (_month == 2 && (_year % 4 == 0 && _year % 100 != 0)
        || (_year % 400 == 0))
        return 29;

    return monthDay[_month];
}

Date Date::operator+(int x)
{
    Date tmp(*this);
    return tmp += x;
}
Date& Date::operator+=(int x)
{
    if (x < 0)
        return *this -= -x;

    _day += x;
    while (_day > getMonthday())
    {
        _day -= getMonthday();
        _month++;
        if (_month == 13)
        {
            _month = 1;
            _year++;
        }
    }
    return *this;
}

int Date::operator-(Date d)
{
    if (*this < d)
        return -1 * (d - *this);

    int cnt = 0;
    while (d + cnt != *this)
        cnt++;

    return cnt;
}

Date Date::operator-(int x)
{
    Date tmp(*this);
    return tmp -= x;
}
Date& Date::operator-=(int x)
{
    if (x < 0)
        return *this += -x;

    _day -= x;
    while (_day <= 0)
    {
        _month--;
        if (_month == 0)
        {
            _month = 12;
            _year--;
        }
        _day += getMonthday();
    }
    return *this;
}

Date& Date::operator++()
{
    return *this += 1;
}
Date Date::operator++(int)
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}
Date& Date::operator--()
{
    return *this -= 1;
}
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

bool Date::operator<(const Date& d)
{
    return _year < d._year
           || (_year == d._year && _month < d._month)
           || (_year == d._year && _month == d._month && _day < d._day);
}
bool Date::operator==(const Date& d)
{
    return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}
bool Date::operator<=(const Date& d)
{
    return *this < d || *this == d;
}
bool Date::operator>(const Date& d)
{
    return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
    return !(*this < d);
}

ostream& operator<<(ostream& out, const Date& d)
{
    return out << d._year << "-" << d._month << "-" << d._day;
}

istream& operator>>(istream& in, Date& d)
{
    return in >> d._year >> d._month >> d._day;
}