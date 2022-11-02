#include <iostream>
#include <cassert>

using namespace std;

typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType _data;
    struct SListNode* _next;
}SLTNode;


SLTNode* BuySLTNode(SLTDataType x)
{
    SLTNode* new_node = (SLTNode*)malloc(sizeof(SLTNode));
    if (new_node == nullptr)
        exit(1);

    new_node->_data = x;
    new_node->_next = nullptr;

    return new_node;
}

SLTNode* CreateSList(int n)
{
    SLTNode* phead = nullptr;
    SLTNode* ptail = nullptr;

    for (int i = 0; i < n; ++i)
    {
        SLTNode* new_node = BuySLTNode(i + 1);
        if (phead == nullptr)
        {
            phead = new_node;
            ptail = new_node;
        }
        else
        {
            ptail->_next = new_node;
            ptail = ptail->_next;
        }
    }

    return phead;
}

void SLTDestory(SLTNode* phead)
{
    SLTNode* pcur = phead;
    while (pcur)
    {
        SLTNode* next = pcur->_next;

        free(pcur);
        pcur = next;
    }

}

void SListPrint(SLTNode* phead)
{
    while (phead != nullptr)
    {
        cout << phead->_data << " ";
        phead = phead->_next;
    }
    cout << "#" << endl;
}

void SLTPushBack(SLTNode** phead, SLTDataType x)
{
    if (*phead == nullptr)
    {
        *phead = BuySLTNode(x);
    }
    else
    {
        SLTNode* tail = *phead;
        while (tail->_next)
            tail = tail->_next;

        tail->_next = BuySLTNode(x);
    }
}

void SLTPopBack(SLTNode* phead)
{

}

void SLTPushFront(SLTNode* phead, SLTDataType x)
{

}

void SLTPopFront(SLTNode* phead)
{

}
