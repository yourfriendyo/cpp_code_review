#include <iostream>
#include "Date.h"

using namespace std;

class A
{
public:
    class B
    {
    public:
        int _b;
    };

private:
    class C
    {
        int _c;
    };
    int _a;
};

int main()
{
    return 0;
}

// int main()
// {
//     Date d1(2023, 3, 11);
//     Date d2(d1);
//     Date d3(2022, 12, 31);
//
//     d3 = d2 = d1;
//     d3.print();
//
//     d1 += 40;
//     d1.print();
//
//     d1 -= 40;
//     d1.print();
//
//     cout << (d1 - d2) << endl;
//
//     cout << (d1 == d2) << endl;
//     cout << (d1 < d2) << endl;
//     cout << (d1 > d2) << endl;
//
//     cout << d1 << endl;
//     cout << d1 << endl;
//
//     return 0;
// }
//