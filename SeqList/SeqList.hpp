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
    assert(s->_size > 0);

    for (int i = 1; i < s->_size; ++i)
        s->_a[i - 1] = s->_a[i];

    s->_size--;
}

int SeqListFind(SL* s, SLDataType x)
{
    for (int i = 0; i < s->_size; ++i)
    {
        if (s->_a[i] == x) return i;
    }

    return -1;
}

void SeqListInsert(SL* s, int pos, SLDataType x)
{
    assert(pos < 0 || pos > s->_size);

    CheckCapacity(s);
    s->_size++;

    for (int i = s->_size; i > pos; --i)
        s->_a[i] = s->_a[i - 1];

    s->_a[pos] = x;
}

void SeqListErase(SL* s, int pos)
{
    assert(s->_size > 0);
    assert(pos < 0 || pos >= s->_size);

    for (int i = pos + 1; i < s->_size; ++i)
        s->_a[i - 1] = s->_a[i];

    s->_size--;
}


void SeqListPrint(SL* s)
{
    for (int i = 0; i < s->_size; i++)
        cout << s->_a[i] << " ";

    cout << endl;
}