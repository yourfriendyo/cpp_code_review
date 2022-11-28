#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
#define BIG_HEAP
#include "Heap.hpp"

using namespace std;

// test heap
void TestHeap()
{
	int a[] = { 5,2,1,9,4,6,3,8,7,0 };
	int sz = sizeof(a) / sizeof(int);
	Heap hp;

	HeapInit(&hp);

	for (int i = 0; i < sz; ++i)
	{
		HeapPush(&hp, a[i]);
		HeapPrint(&hp);
	}

	cout << endl;

	for (int i = 0; i < sz; ++i)
	{
		HeapPrint(&hp);
		HeapPop(&hp);
	}

	cout << endl;

	Heap tmp = HeapCreate(a, sz);
	HeapPrint(&tmp);
	cout << endl;

	HeapBuild(a, sz);
	for (auto e : a) cout << e << " ";
	cout << endl;

	HeapDestroy(&hp);
}

// heap sort
void HeapSort()
{
	int a[] = { 5,2,1,9,4,6,3,8,7,0 };
	int n = sizeof(a) / sizeof(int);

	for (int i = (n - 2) / 2; i >= 0; --i)
		AdjustDown(a, n, i);

	for (int i = n - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
	}

	for (auto e : a) cout << e << " ";
	cout << endl;
}

// topk
void TopK(int k = 5)
{
	FILE* fin = fopen("Data.txt", "r");
	assert(fin);
	int* minHeap = (int*)malloc(sizeof(int) * k);
	assert(minHeap);

	for (int i = 0; i < k; i++)
		fscanf(fin, "%d", &minHeap[i]);

	int val = 0;
	while (fscanf(fin, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
		cout << minHeap[i] << " ";
	cout << endl;

	free(minHeap);
	fclose(fin);
}

int main()
{
	//TestHeap();
	HeapSort();
	TopK();
}
