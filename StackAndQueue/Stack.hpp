#pragma once
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

typedef int STDataType;

typedef struct Stack
{
    STDataType* data;
    int top;
    int capacity;
}ST;

void StackInit(ST* st)
{
    assert(st);

    st->data = (STDataType*)malloc(sizeof(STDataType) * 4);
    assert(st->data);

    st->top = 0;
    st->capacity = 4;
}

void StackDestory(ST* st)
{
    assert(st);

    free(st->data);
    st->top = st->capacity = 0;
}

void CheckCapacity(ST* st)
{
    if (st->top == st->capacity)
    {
        int newCapacity = st->capacity == 0 ? 4 : st->capacity * 2;
        st->data = (STDataType*)realloc(st->data, sizeof(STDataType) * newCapacity);
        assert(st->data);

        st->capacity = newCapacity;
    }
}

void StackPush(ST* st, STDataType x)
{
    assert(st);
    CheckCapacity(st);
    st->data[st->top++] = x;
}

void StackPop(ST* st)
{
    assert(st && st->top > 0);
    st->top--;
}

bool StackEmpty(ST* st)
{
    return st->top == 0;
}

int StackSize(ST* st)
{
    return st->top;
}

STDataType StackTop(ST* st)
{
    assert(st->top > 0);
    return st->data[st->top - 1];
}
