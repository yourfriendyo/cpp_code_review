#include <iostream>
#include "SeqList.hpp"

using namespace std;


void TestSeqList1()
{
    SL s;
    SeqListInit(&s);

    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);

    // SeqListPopBack(&s);
    // SeqListPopBack(&s);

    // SeqListPushBack(&s, 14);
    // SeqListPushBack(&s, 15);

    SeqListPushFront(&s, 0);
    SeqListPushFront(&s, -1);
    SeqListPopFront(&s);
    SeqListPopFront(&s);

    SeqListPrint(&s);

    SeqListDestroy(&s);
}

int main()
{
    TestSeqList1();

    return 0;
}
