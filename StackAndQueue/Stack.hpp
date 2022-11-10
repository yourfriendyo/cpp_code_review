#pragma once
#include <iostream>
#include <cassert>

using namespace std;

typedef int DataType;

typedef struct Stack
{
    DataType* data;
    int top;
    int capacity;
}ST;