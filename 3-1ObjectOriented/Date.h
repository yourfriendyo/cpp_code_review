#pragma once
#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend ostream& operator>>(ostream& out, const Date& d);

public:
    Date(int year = 1, int month = 1, int day = 1);
    ~Date();
    Date(const Date& d);
    Date& operator=(const Date& d);

    int  getMonthday();
    void print() { cout << _year << "-" << _month << "-" << _day << endl; }

    Date  operator+(int x);
    Date& operator+=(int x);

    int   operator-(Date d);
    Date  operator-(int x);
    Date& operator-=(int x);

    Date& operator++();
    Date  operator++(int);
    Date& operator--();
    Date  operator--(int);

    bool operator<(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator<=(const Date& d);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);

private:
    int _year;
    int _month;
    int _day;
};
