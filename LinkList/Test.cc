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

}


int main()
{

    return 0;
}