#include <iostream>

#define BIG_HEAP
#include "Heap.hpp"

using namespace std;


void TestHeap1()
{
    Heap hp;
    HeapInit(&hp);

    int arr[] = { 4,3,1,9,2,5,8,6,0,7 };
    int sz = sizeof(arr) / sizeof(int);

    for (int i = 0; i < sz; i++)
    {
        HeapPush(&hp, arr[i]);
        HeapPrint(&hp);
    }

    cout << endl;

    for (int i = 0; i < sz; i++)
    {
        HeapPrint(&hp);
        HeapPop(&hp);
    }

    HeapDestroy(&hp);
}

void TestTopK(int k)
{
    Heap hp;
    HeapInit(&hp);

    int arr[] = { 4,3,1,9,2,5,8,6,0,7 };
    int sz = sizeof(arr) / sizeof(int);

#ifdef BIG_HEAP
    // 1. 选第k大的数，建大堆
    for (int i = 0; i < sz; i++)
        HeapPush(&hp, arr[i]);

    while (k--)
    {
        cout << HeapTop(&hp) << endl;
        HeapPop(&hp);
    }

#else
    //

#endif

    HeapDestroy(&hp);
}

void TestHeapSort()
{
    Heap hp;
    HeapInit(&hp);

    int arr[] = { 4,3,1,9,2,5,8,6,0,7 };
    int sz = sizeof(arr) / sizeof(int);

    for (int i = 0; i < sz; i++)
        HeapPush(&hp, arr[i]);

    for (int i = 0; i < sz; i++) {
        cout << HeapTop(&hp) << " ";
        HeapPop(&hp);
    }

    HeapDestroy(&hp);
}

int main()
{
    // TestHeap1();

    // TestTopK(2);

    TestHeapSort();

    return 0;
}