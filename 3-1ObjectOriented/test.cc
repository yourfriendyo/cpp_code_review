#include <iostream>

using namespace std;


class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year  = year;
        _month = month;
        _day   = day;
    }

    Date(const Date& d)
    {
        _year  = d._year;
        _month = d._month;
        _day   = d._day;
    }

    Date& operator=(const Date& d)
    {
        if (*this != d)
        {
            _year  = d._year;
            _month = d._month;
            _day   = d._day;
        }
        return *this;
    }

    int getMonthDay()
    {
        static int monthDay[13]
            = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (_month == 2
                && (_year % 4 == 0 && _year % 100 != 0)
            || (_year % 400 == 0))
            return 29;

        return monthDay[_month];
    }

    Date operator+(int x)
    {
        Date tmp(*this);
        tmp += x;

        return tmp;
    }

    Date& operator+=(int x)
    {
        if (x < 0)
            return *this -= (-1 * x);

        _day += x;
        while (_day > getMonthDay())
        {
            _day -= getMonthDay();
            _month++;

            if (_month > 12)
            {
                _month = 1;
                _year++;
            }
        }

        return *this;
    }

    Date operator-(int x)
    {
        Date& tmp(*this);
        tmp -= x;

        return tmp;
    }

    Date& operator-=(int x)
    {
        if (x < 0)
            return *this += (-1 * x);

        _day -= x;
        while (_day <= 0)
        {
            _month--;
            if (_month == 0)
            {
                _month = 12;
                _year--;
            }
            _day += getMonthDay();
        }
        return *this;
    }

    int operator-(Date d)
    {
        if (*this < d)
            return -1 * (d - *this);

        int cnt = 0;
        while (d + cnt != *this)
            cnt++;

        return cnt;
    }

    bool operator==(const Date& d)
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator!=(const Date& d)
    {
        return !(*this == d);
    }

    bool operator<(const Date& d)
    {
        if (_year < d._year)
            return true;
        else if (_year == d._year && _month < d._month)
            return true;
        else if (_year == d._year && _month == d._month && _day < d._day)
            return true;
        else
            return false;
    }

    bool operator<=(const Date& d)
    {
        return (*this == d) || (*this < d);
    }

    bool operator>(const Date& d)
    {
        return !(*this <= d);
    }

    bool operator>=(const Date& d)
    {
        return !(*this < d);
    }

    void print()
    {
        cout << _year << " " << _month << " " << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1(2023, 1, 11);
    Date d2(2022, 12, 31);

    cout << (d1 - d2) << endl;
    cout << (d2 - d1) << endl;

    return 0;
}
