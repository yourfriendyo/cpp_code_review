#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
#include <cstdlib>

// #define BIG_HEAP
#include "Heap.hpp"

using namespace std;

void TestHeap()
{
	int a[] = { 2,5,3,7,1,9,0,4,8,6 };
	int sz = sizeof(a) / sizeof(int);
	Heap hp;
	HeapInit(&hp);

	// for (int i = 0; i < sz; i++)
	// {
	// 	HeapPush(&hp, a[i]);
	// 	HeapPrint(&hp);
	// }
	//
	// cout << endl;
	//
	// for (int i = 0; i < sz; i++)
	// {
	// 	HeapPrint(&hp);
	// 	HeapPop(&hp);
	// }

	HeapCreate(&hp, a, sz);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

void TestTopK(int k)
{
	// 随机写入
	int n = 10000;
	srand((unsigned int)time(nullptr));

	FILE* fin = fopen("Data.txt", "w");
	assert(fin);
	for (int i = 0; i < n; i++)
		fprintf(fin, "%d\n", rand());


	int* minHeap = (int*)malloc(sizeof(int) * k);
	FILE* fout = fopen("Data.txt", "r");
	assert(minHeap && fout);
	memset(minHeap, 0, k);

	// 建堆
	for (int i = 0; i < k; i++)
		fscanf(fout, "%d", &minHeap[i]);
	for (int i = (k - 2) / 2; i >= 0; --i)
		AdjustDown(minHeap, k, i);

	// 比较
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
			minHeap[0] = val;
		AdjustDown(minHeap, k, 0);
	}

	// 打印
	for (int i = 0; i < k; i++)
		cout << minHeap[i] << endl;
}

void HeapSort(int* a, int n)
{
	// 1. 建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(a, n, i);

	// 2.
	for (int i = n - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0); // 剩余元素个数正好为i
	}
}

void TestHeapSort()
{
	int a[] = { 2,5,3,7,1,9,0,4,8,6 };
	int sz = sizeof(a) / sizeof(int);

	HeapSort(a, sz);

	for (auto e : a)
		cout << e << " ";
	cout << endl;
}

int main()
{
	// TestHeap();

	TestTopK(5);

	// TestHeapSort();


	return 0;
}
