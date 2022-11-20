#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
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

void AdjustUp(int* a, int child);

void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;

		hp->a = (HPDataType*)realloc(hp->a, newCapacity * sizeof(int));
		assert(hp->a);

		hp->capacity = newCapacity;
	}

	hp->a[hp->size++] = x;

	AdjustUp(hp->a, hp->size - 1);
}

void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
#ifdef BIG_HEAP
		if (a[child] > a[parent])
#else
		if (a[child] < a[parent])
#endif
			swap(a[child], a[parent]);
		else
			break;

		child = parent;
		parent = (child - 1) / 2;
	}
}

void AdjustDown(int* a, int size, int parent);

void HeapPop(Heap* hp)
{
	assert(hp && hp->size);

	hp->a[0] = hp->a[hp->size - 1];
	hp->size--;

	AdjustDown(hp->a, hp->size, 0);
}

void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
			child = child + 1;

		if (a[child] > a[parent])
			swap(a[parent], a[child]);
		else
			break;

		parent = child;
		child = parent * 2 + 1;
	}
}

void HeapPrint(Heap* hp)
{
	int i = 0;

	for (int i = 0; i < hp->size; i++)
		cout << hp->a[i] << " ";

	cout << endl;

}
