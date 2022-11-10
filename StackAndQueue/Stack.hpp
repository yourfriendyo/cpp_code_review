#pragma once
#include <iostream>
#include <cassert>

using namespace std;

typedef int STDataType;

typedef struct Stack
{
    STDataType* data;
    int top;
    int capacity;
}ST;
