#pragma once
#include <iostream>
#include <cassert>

using namespace std;

typedef int SLDataType;

typedef struct SeqList
{
    SLDataType* _a;
    int _size;
    int _capacity;
}SL;

void SeqListInit(SL* s)
{
    assert(s);

    s->_a = NULL;
    s->_size = 0;
    s->_capacity = 0;
}

void SeqListDestroy(SL* s)
{
    assert(s);

    if (s->_a)
    {
        free(s->_a);
        s->_a = NULL;
        s->_size = s->_capacity = 0;
    }
}

void CheckCapacity(SL* s)
{
    if (s->_size == s->_capacity)
    {
        int newCapacity = s->_capacity == 0 ? 4 : s->_capacity * 2;
        SLDataType* tmp = (SLDataType*)realloc(s->_a, sizeof(SLDataType) * newCapacity);
        if (tmp == NULL)
            exit(1);

        s->_a = tmp;
        s->_capacity = newCapacity;
    }
}

void SeqListPushBack(SL* s, SLDataType x)
{
    CheckCapacity(s);

    s->_a[s->_size] = x;
    s->_size++;
}

void SeqListPopBack(SL* s)
{
    assert(s->_size > 0);
    s->_size--;
}

void SeqListPushFront(SL* s, SLDataType x)
{
    CheckCapacity(s);

    s->_size++;
    for (int i = s->_size; i > 0; --i)
        s->_a[i] = s->_a[i - 1];

    s->_a[0] = x;
}

void SeqListPopFront(SL* s)
{

}


void SeqListPrint(SL* s)
{
    for (int i = 0; i < s->_size; i++)
        cout << s->_a[i] << " ";

    cout << endl;
}
