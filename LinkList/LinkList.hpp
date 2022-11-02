#include <iostream>
#include <cassert>

using namespace std;

typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType _data;
    struct SListNode* _next;
}SLTNode;


SLTNode* BuySLTNode(SLTDataType x)
{
    SLTNode* new_node = (SLTNode*)malloc(sizeof(SLTNode));
    if (new_node == nullptr)
        exit(1);

    new_node->_data = x;
    new_node->_next = nullptr;

    return new_node;
}