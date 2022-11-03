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

void SLTPrint(SLTNode** phead)
{
    assert(phead);

    SLTNode* cur = *phead;

    while (cur != nullptr)
    {
        cout << cur->_data << " ";
        cur = cur->_next;
    }
    cout << "#" << endl;
}

void SLTPushBack(SLTNode** phead, SLTDataType x)
{
    assert(phead);

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

void SLTPopBack(SLTNode** phead)
{
    assert(phead && *phead);

    if ((*phead)->_next == nullptr)
    {
        free(*phead);
        *phead = nullptr;
    }
    else
    {
        SLTNode* prev = nullptr;
        SLTNode* tail = *phead;

        while (tail->_next)
        {
            prev = tail;
            tail = tail->_next;
        }

        free(tail);
        prev->_next = nullptr;
    }
}

void SLTPushFront(SLTNode** phead, SLTDataType x)
{
    assert(phead);

    SLTNode* new_node = BuySLTNode(x);
    new_node->_next = *phead;

    (*phead) = new_node;
}

void SLTPopFront(SLTNode** phead)
{
    assert(phead && *phead);

    SLTNode* next = (*phead)->_next;
    free(*phead);

    *phead = next;
}

SLTNode* SLTFind(SLTNode** phead, SLTDataType x)
{
    SLTNode* cur = *phead;
    while (cur && cur->_data != x)
        cur = cur->_next;

    return cur;
}

void SLTInsertAfter(SLTNode** phead, SLTNode* pos, SLTDataType x)
{
    assert(phead && *phead && pos);

    SLTNode* newNode = BuySLTNode(x);

    newNode->_next = pos->_next;
    pos->_next = newNode;
}

void SLTInsert(SLTNode** phead, SLTNode* pos, SLTDataType x)
{
    if (pos == *phead)
        SLTPushFront(phead, x);
    else if (pos == nullptr)
        SLTPushBack(phead, x);
    else
    {
        SLTNode* prev = *phead;
        while (prev && prev->_next != pos)
            prev = prev->_next;

        if (prev == nullptr)
            exit(-3);

        SLTNode* newNode = BuySLTNode(x);
        prev->_next = newNode;
        newNode->_next = pos;
    }
}

void SLTEraseAfter(SLTNode** phead, SLTNode* pos)
{
    assert(phead && *phead && pos);

    if (pos->_next == nullptr)
        return;

    SLTNode* nextNext = pos->_next->_next;

    free(pos->_next);
    pos->_next = nextNext;
}

void SLTErase(SLTNode** phead, SLTNode* pos)
{
    if (*phead == pos)
        SLTPopFront(phead);
    else if (pos == nullptr)
        SLTPopBack(phead);
    else
    {
        SLTNode* prev = *phead;
        while (prev && prev->_next != pos)
            prev = prev->_next;

        if (prev == nullptr)
            exit(-4);

        prev->_next = pos->_next;
        free(pos);
    }
}
