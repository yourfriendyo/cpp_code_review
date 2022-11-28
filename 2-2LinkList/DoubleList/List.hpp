#pragma once
#include <iostream>
#include <cassert>

using namespace std;

typedef int LTDataType;

typedef struct ListNode
{
    LTDataType val;
    struct ListNode* prev;
    struct ListNode* next;
}DLTNode;

DLTNode* BuyLTNode(LTDataType x)
{
    DLTNode* node = (DLTNode*)malloc(sizeof(DLTNode));
    if (node == nullptr)
        exit(1);
    node->val = x;
    node->next = node->prev = nullptr;

    return node;
}
DLTNode* DLTInit()
{
    DLTNode* head = BuyLTNode(-1);
    head->next = head;
    head->prev = head;

    return head;
}

void DLTPushBack(DLTNode* head, LTDataType x)
{
    assert(head);
    DLTNode* tail = head->prev;
    DLTNode* newNode = BuyLTNode(x);

    head->prev = newNode;
    newNode->next = head;

    tail->next = newNode;
    newNode->prev = tail;
}

void DLTPopBack(DLTNode* head)
{
    assert(head && head->prev != head);

    DLTNode* tail = head->prev;
    DLTNode* prevTail = tail->prev;

    head->prev = prevTail;
    prevTail->next = head;

    free(tail);
}

void DLTPushFront(DLTNode* head, LTDataType x)
{
    assert(head);

    DLTNode* newNode = BuyLTNode(x);
    DLTNode* first = head->next;

    head->next = newNode;
    newNode->prev = head;

    newNode->next = first;
    first->prev = newNode;
}

void DLTPopFront(DLTNode* head)
{
    assert(head && head->next != head);

    DLTNode* first = head->next;
    DLTNode* second = head->next->next;

    head->next = second;
    second->prev = head;

    free(first);
}

void DLTPrint(DLTNode* head)
{
    DLTNode* cur = head->next;

    while (cur != head)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}