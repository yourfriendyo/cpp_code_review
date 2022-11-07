#pragma once
#include <iostream>
#include <cassert>

typedef int DLTDataType;

typedef struct ListNode
{
    DLTDataType val;
    struct ListNode* prev;
    struct ListNode* next;
}DLNode;