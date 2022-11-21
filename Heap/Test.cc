#include <iostream>
#include <cassert>

#define BIG_HEAP
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
	int a[] = { 2,5,3,7,1,9,0,4,8,6 };
	int sz = sizeof(a) / sizeof(int);

	HeapBuild(a, sz);

	for (auto e : a)
		cout << e << " ";

	cout << endl;
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(a, n, i);


}

void TestHeapSort()
{
	int a[] = { 2,5,3,7,1,9,0,4,8,6 };
	int sz = sizeof(a) / sizeof(int);

	HeapSort(a, sz);
}

int main()
{
	// TestHeap();

	TestTopK(2);

	TestHeapSort();


	return 0;
}
