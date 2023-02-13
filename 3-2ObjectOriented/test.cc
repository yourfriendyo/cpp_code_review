#include <iostream>
#include <type_traits>
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

    int getMonthDay()
    {
        static int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (_month == 2 && (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
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
    Date d(2023, 2, 11);
    d += 2;
    d.print();

    return 0;
}
