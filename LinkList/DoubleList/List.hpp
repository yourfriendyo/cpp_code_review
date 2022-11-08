#pragma once
#include <iostream>
#include <cassert>

using namespace std;

typedef int DLTDataType;

typedef struct ListNode
{
    DLTDataType val;
    struct ListNode* prev;
    struct ListNode* next;
}DLTNode;


DLTNode* BuyDLTNode(DLTDataType x)
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
    DLTNode* head = BuyDLTNode(-1);
    head->next = head;
    head->prev = head;

    return head;
}

void DLTPushBack(DLTNode* head, DLTDataType x)
{
    assert(head);

    DLTNode* newNode = BuyDLTNode(x);
    DLTNode* tail = head->prev;

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

void DLTPushFront(DLTNode* head, DLTDataType x)
{
    assert(head);

    DLTNode* newNode = BuyDLTNode(x);
    DLTNode* front = head->next;

    newNode->prev = head;
    head->next = newNode;

    front->prev = newNode;
    newNode->next = front;
}

void DLTPopFront(DLTNode* head)
{
    assert(head && head->next != head);
    DLTNode* first = head->next;
    DLTNode* second = first->next;

    head->next = second;
    second->prev = head;

    free(first);
}

void DLTPrint(DLTNode* list)
{
    assert(list);
    DLTNode* cur = list->next;

    while (cur != list)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }

    cout << endl;
}