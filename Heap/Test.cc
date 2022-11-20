#include <iostream>

#define BIG_HEAP
#include "Heap.hpp"

using namespace std;


int main()
{
    Heap hp;
    HeapInit(&hp);

    int arr[] = { 4,3,1,9,2,5,8,6,0,7 };
    int sz = sizeof(arr) / sizeof(int);

    for (int i = 0; i < sz; i++)
        HeapPush(&hp, arr[i]);

    HeapPrint(&hp);

    HeapDestroy(&hp);

    return 0;
}
