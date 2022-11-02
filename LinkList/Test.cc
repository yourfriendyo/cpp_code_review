#include <iostream>
#include "LinkList.hpp"

using namespace std;

void TestSList1()
{
    SLTNode* n1 = BuySLTNode(1);
    SLTNode* n2 = BuySLTNode(2);
    SLTNode* n3 = BuySLTNode(3);
    SLTNode* n4 = BuySLTNode(4);

    n1->_next = n2;
    n2->_next = n3;
    n3->_next = n4;
    n4->_next = nullptr;

    CreateSList(3);

    SListPrint(n1);
}

void TestSList2()
{
    SLTNode* plist = nullptr;
    // SLTNode* plist = CreateSList(5);
    SListPrint(plist);

    SLTPushBack(&plist, 6);
    SLTPushBack(&plist, 7);

    SListPrint(plist);

}


int main()
{

    // TestSList1();
    TestSList2();

    return 0;
}