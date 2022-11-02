#include <iostream>
#include "SeqList.hpp"

using namespace std;


void TestSeqList1()
{
    SL sl;
    SeqListInit(&sl);

    SeqListPushBack(&sl, 1);
    SeqListPushBack(&sl, 2);
    SeqListPushBack(&sl, 3);
    SeqListPushBack(&sl, 4);
    SeqListPushBack(&sl, 5);

    SeqListPopBack(&sl);
    SeqListPopBack(&sl);
    SeqListPopBack(&sl);
    SeqListPopBack(&sl);
    // SeqListPopBack(&sl);


    SeqListDestory(&sl);
}

void TestSeqList2()
{
    SL sl;
    SeqListInit(&sl);

    SeqListPushBack(&sl, 1);
    SeqListPushBack(&sl, 2);

    SeqListPushFront(&sl, 0);
    SeqListPushFront(&sl, -1);
    SeqListPushFront(&sl, -2);

    SeqListPopFront(&sl);
    SeqListPopFront(&sl);
    SeqListPopFront(&sl);

    SeqListDestory(&sl);
}

void TestSeqList3()
{
    SL sl;
    SeqListInit(&sl);

    SeqListInsert(&sl, 0, 1);
    SeqListInsert(&sl, 1, 2);
    SeqListInsert(&sl, 2, 3);
    SeqListInsert(&sl, 3, 4);
    SeqListInsert(&sl, 4, 5);

    SeqListErase(&sl, 0);
    SeqListErase(&sl, 1);
    SeqListErase(&sl, 2);
    SeqListErase(&sl, 3);
    SeqListErase(&sl, 4);

    SeqListDestory(&sl);
}

int main()
{
    // TestSeqList1();
    // TestSeqList2();
    // TestSeqList3();

    return 0;
}