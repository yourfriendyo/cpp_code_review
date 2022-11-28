#include <iostream>
#include <cassert>

using namespace std;

typedef struct Heap
{
    int* a;
    int size;
    int capacity;
}Heap;

void HeapInit(Heap* hp)
{
    assert(hp);
    hp->a = nullptr;
    hp->size = hp->capacity = 0;
}

void HeapDestroy(Heap* hp)
{
    assert(hp);
    free(hp->a);
    hp->a = nullptr;
    hp->size = hp->capacity = 0;
}

void AdjustUp(int* a, int child)
{
    int parent = (child - 1) / 2;

    while (child > 0)
    {
        if (a[child] < a[parent])
            swap(a[child], a[parent]);
        else
            break;

        child = parent;
        parent = (child - 1) / 2;
    }
}

void HeapPush(Heap* hp, int x)
{
    assert(hp);

    if (hp->size == hp->capacity)
    {
        int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
        hp->a = (int*)realloc(hp->a, newCapacity * sizeof(int));
        assert(hp->a);

        hp->capacity = newCapacity;
    }

    hp->a[hp->size] = x;
    hp->size++;

    AdjustUp(hp->a, hp->size - 1);
}

void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;

    while (child < n)
    {
        if (child + 1 < n && a[child + 1] < a[child])
            child++;

        if (a[child] < a[parent])
            swap(a[child], a[parent]);
        else
            break;

        parent = child;
        child = parent * 2 + 1;
    }
}

void HeapPop(Heap* hp)
{
    assert(hp && hp->size);

    hp->a[0] = hp->a[hp->size - 1];
    hp->size--;

    AdjustDown(hp->a, hp->size, 0);
}

void HeapBuild(int* a, int n)
{
    for (int i = (n - 2) / 2; i >= 0; --i)
        AdjustDown(a, n, i);
}

Heap HeapCreate(int* a, int n)
{
    Heap hp;
    HeapInit(&hp);

    hp.a = (int*)malloc(n * sizeof(int));
    _memccpy(hp.a, a,sizeof(int), n);
    hp.size = hp.capacity = n;

    return hp;
}

void HeapPrint(Heap* hp)
{
    for (int i = 0; i < hp->size; i++)
        cout << hp->a[i] << " ";

    cout << endl;
}