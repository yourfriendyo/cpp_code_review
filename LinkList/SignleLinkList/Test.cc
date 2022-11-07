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

    SLTPrint(&n1);
}

void TestSList2()
{
    // SLTNode* plist = nullptr;
    SLTNode* plist = CreateSList(4);
    SLTPrint(&plist);

    SLTPopBack(&plist);
    SLTPrint(&plist);

    SLTPopBack(&plist);
    SLTPrint(&plist);

    SLTPopBack(&plist);
    SLTPrint(&plist);

    SLTPopBack(&plist);

    SLTPrint(&plist);

    // SLTPopBack(&plist);
}

void TestSList3()
{
    SLTNode* plist = nullptr;
    // SLTNode* plist = CreateSList(1);

    SLTPushFront(&plist, 0);
    SLTPopFront(&plist);
    SLTPrint(&plist);

    SLTPushFront(&plist, -1);
    SLTPopFront(&plist);
    SLTPrint(&plist);

    SLTPushFront(&plist, -2);
    SLTPopFront(&plist);
    SLTPrint(&plist);

    // SLTPopFront(&plist);
}


void TestSList4()
{
    SLTNode* plist = BuySLTNode(1);

    SLTInsert(&plist, SLTFind(&plist, 1), 0);
    SLTPrint(&plist);

    SLTInsertAfter(&plist, SLTFind(&plist, 1), 2);
    SLTPrint(&plist);

    SLTEraseAfter(&plist, SLTFind(&plist, 0));
    SLTPrint(&plist);

    SLTErase(&plist, SLTFind(&plist, 0));
    SLTPrint(&plist);

    SLTErase(&plist, SLTFind(&plist, 2));
    SLTPrint(&plist);

}

int main()
{

    // TestSList1();
    // TestSList2();
    // TestSList3();
    TestSList4();

    return 0;
}