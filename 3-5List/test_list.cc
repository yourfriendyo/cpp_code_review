#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include "list.h"

using namespace std;

void test_list_1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;


}

int main()
{
    test::test_list_1();
    return 0;
}