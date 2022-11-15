#include <iostream>
#include <cassert>
#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;
void TestStack()
{
    ST st;

    StackInit(&st);

    StackPush(&st, 1);
    cout << StackTop(&st) << endl;
    StackPush(&st, 2);
    cout << StackTop(&st) << endl;
    StackPush(&st, 3);
    cout << StackTop(&st) << endl;
    StackPush(&st, 4);
    cout << StackTop(&st) << endl;
    StackPush(&st, 5);
    cout << StackTop(&st) << endl;

    cout << "stack is Empty ? " << StackEmpty(&st) << endl;
    cout << "stack size ? " << StackSize(&st) << endl;

    StackPop(&st);
    cout << StackTop(&st) << endl;
    StackPop(&st);
    cout << StackTop(&st) << endl;
    StackPop(&st);
    cout << StackTop(&st) << endl;
    StackPop(&st);
    cout << StackTop(&st) << endl;
    StackPop(&st);
    // cout << StackTop(&st) << endl; //Assert

    cout << "stack is Empty ? " << StackEmpty(&st) << endl;
    cout << "stack size ? " << StackSize(&st) << endl;

    StackDestory(&st);
}

void TestQueue()
{

}


int main()
{
    TestStack();

    TestQueue();

    return 0;
}
