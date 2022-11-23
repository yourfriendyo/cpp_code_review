#pragma once
#include <iostream>
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

void HeapBuild(int* a, int n);

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);

	HeapInit(hp);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	assert(hp->a);

	memcpy(hp->a, a, sizeof(HPDataType) * n);

	hp->size = hp->capacity = n;

	HeapBuild(hp->a, n);
}

void AdjustUp(int* a, int child);
void AdjustDown(int* a, int n, int parent);

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		hp->a = (HPDataType*)realloc(hp->a, newCapacity * sizeof(HPDataType));
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

void HeapPop(Heap* hp)
{
	assert(hp && hp->size);

	hp->a[0] = hp->a[hp->size - 1];
	hp->size--;

	AdjustDown(hp->a, hp->size, 0);
}


void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
#ifdef BIG_HEAP
		if (child + 1 < n && a[child + 1] > a[child])
#else
		if (child + 1 < n && a[child + 1] < a[child])
#endif
			child++;

#ifdef BIG_HEAP
		if (a[child] > a[parent])
#else
		if (a[child] < a[parent])
#endif
			swap(a[child], a[parent]);
		else
			break;

		parent = child;
		child = parent * 2 + 1;
	}
}

void HeapBuild(HPDataType* a, int n)
{
	// #define ADJST_DN
#ifdef ADJST_DN
	// 向上调整
	for (int i = 1; i < n; i++)
		AdjustUp(a, i);

#else

	// 向下调整
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
		AdjustDown(a, n, i);
#endif
}

void HeapPrint(Heap* hp)
{
	assert(hp);

	for (int i = 0; i < hp->size; i++)
		cout << hp->a[i] << " ";

	cout << endl;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

int HeapTop(Heap* hp)
{
	assert(hp && hp->size);
	return hp->a[0];
}

bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size;
}
