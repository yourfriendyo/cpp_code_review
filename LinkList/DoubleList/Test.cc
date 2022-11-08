#include <iostream>
#include "List.hpp"

using namespace std;

void TestDList1()
{
    DLTNode* list = DLTInit();

    DLTPushBack(list, 0);
    DLTPrint(list);
    DLTPushBack(list, 1);
    DLTPrint(list);
    DLTPushBack(list, 2);
    DLTPrint(list);

    DLTPopBack(list);
    DLTPrint(list);
    DLTPopBack(list);
    DLTPrint(list);
    DLTPopBack(list);
    DLTPrint(list);
}

void TestDList2()
{
    DLTNode* list = DLTInit();

    DLTPushFront(list, 0);
    DLTPrint(list);
    DLTPushFront(list, 1);
    DLTPrint(list);
    DLTPushFront(list, 2);
    DLTPrint(list);

    DLTPopFront(list);
    DLTPrint(list);
    DLTPopFront(list);
    DLTPrint(list);
    DLTPopFront(list);
    DLTPrint(list);

}

int main()
{
    TestDList1();
    cout << "----------------------------------------" << endl;
    TestDList2();

    return 0;
}