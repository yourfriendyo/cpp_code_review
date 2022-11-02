#pragma once
#include <iostream>
#include <cassert>

typedef int SLDataType;

typedef struct SeqList
{
    SLDataType* _data;
    int _size;
    int _capacity;
}SL;

void SeqListInit(SL* s)
{
    assert(s);

    s->_data = nullptr;
    s->_size = s->_capacity = 0;
}

void CheckCapacity(SL* s)
{
    if (s->_size == s->_capacity)
    {
        int newCapacity = s->_capacity == 0 ? 4 : s->_capacity * 2;

        SLDataType* tmp = (SLDataType*)realloc(s->_data, sizeof(int) * newCapacity);
        if (tmp == nullptr)
            exit(-1);

        s->_data = tmp;
        s->_capacity = newCapacity;
    }
}

void SeqListPushBack(SL* s, SLDataType x)
{
    CheckCapacity(s);

    s->_data[s->_size] = x;
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

    for (int i = s->_size; i > 0; --i)
        s->_data[i] = s->_data[i - 1];

    s->_data[0] = x;
    s->_size++;
}

void SeqListPopFront(SL* s)
{
    assert(s->_size > 0);

    for (int i = 0; i < s->_size - 1; ++i)
        s->_data[i] = s->_data[i + 1];

    s->_size--;
}

int SeqListFind(SL* s, SLDataType x)
{
    for (int i = 0; i < s->_size; ++i)
        if (s->_data[i] == x)
            return i;

    return 1;
}

void SeqListInsert(SL* s, int pos, SLDataType x)
{
    assert(0 <= pos && pos <= s->_size);
    CheckCapacity(s);

    for (int i = s->_size; i > pos; --i)
        s->_data[i] = s->_data[i - 1];

    s->_data[pos] = x;
    s->_size++;
}

void SeqListErase(SL* s, int pos)
{
    assert(s->_size > 0);
    assert(0 <= pos && pos < s->_size);

    for (int i = pos; i < s->_size - 1; ++i)
        s->_data[i] = s->_data[i + 1];

    s->_size--;
}

void SeqListDestory(SL* s)
{
    //assert(s);

    free(s->_data);
    s->_data = nullptr;
    s->_size = s->_capacity = 0;
}

void SeqListPrint(SL* s)
{
    for (int i = 0; i < s->_size; ++i)
        cout << s->_data[i] << " ";

    cout << endl;
}
