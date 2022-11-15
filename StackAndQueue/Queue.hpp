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
    int size;
}QE;

void QueueInit(QE* q)
{
    assert(q);
    q->head = q->tail = nullptr;
    q->size = 0;
}

void QueueDestroy(QE* q)
{
    assert(q);
    QNode* cur = q->head;

    while (cur)
    {
        QNode* del = cur;
        cur = cur->next;

        free(del);
    }

    q->head = q->tail = nullptr;
    q->size = 0;
}

void QueuePush(QE* q, QEDataType x)
{
    assert(q);

    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    assert(newNode);
    newNode->val = x;
    newNode->next = nullptr;

    if (q->head == nullptr)
    {
        q->head = q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;
}

void QueuePop(QE* q)
{
    assert(q && q->head);

    QNode* del = q->head;

    if (q->head == q->tail)
        q->head = nullptr;
    else
        q->head = q->head->next;

    free(del);
    q->size--;
}

int QueueSize(QE* q)
{
    assert(q);
    return q->size;
}

bool QueueEmpty(QE* q)
{
    assert(q);
    return q->head == nullptr;
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