#pragma once
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <cstdlib>

using namespace std;

typedef int QEDataType;

typedef struct QueueNode
{
    QEDataType val;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
}QE;

void QueueInit(QE* q)
{
    assert(q);
    q->head = q->tail = nullptr;
}

void QueueDestroy(QE* q)
{
    assert(q);
    QNode* cur = q->head;

    while (cur != nullptr)
    {
        QNode* del = cur;
        cur = cur->next;
        free(del);
    }

    q->head = q->tail = nullptr;
    free(q);
}

void QueuePush(QE* q, QEDataType val)
{
    assert(q);
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    assert(newNode);

    newNode->val = val;
    newNode->next = nullptr;

    if (q->tail == nullptr)
    {
        q->head = q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

void QueuePop(QE* q)
{
    assert(q && q->head);

    QNode* del = q->head;

    if (q->head == q->tail)
        q->head = q->tail = nullptr;
    else
        q->head = q->head->next;

    free(del);
}

QEDataType QueueFront(QE* q)
{
    assert(q && q->head);
    return q->head->val;
}

QEDataType QueueBack(QE* q)
{
    assert(q && q->head);
    return q->tail->val;
}

bool QueueEmpty(QE* q)
{
    return q->head == nullptr;
}

int QueueSize(QE* q)
{
    int size = 0;
    QNode* cur = q->head;

    while (cur)
    {
        size++;
        cur = cur->next;
    }

    return size;
}
