#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cassert>
#include "insert_sort.hpp"
#include "select_sort.hpp"
#include "swap_sort.hpp"
#include "merge_sort.hpp"
#include "count_sort.hpp"

using namespace std;

typedef void (*call_back) (int*, int);

void print_arr(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void test_sort(call_back sort)
{
    cout << "--------------------" << endl;

    int a[] = { 8,3,0,7,2,9,1,6,4,5 };
    // int a[] = { 1,1,1,1,1,1,1,1,1,1 };
    // int a[] = { 0,1,2,3,4,5,6,7,8,9 };
    int n = sizeof(a) / sizeof(int);

    print_arr(a, n);
    sort(a, n);
    print_arr(a, n);
}

void TestOP();

int main()
{
    // TestOP();
    // test_sort(insert_sort);
    // test_sort(shell_sort);
    // test_sort(shell_sort_simp);
    // test_sort(select_sort);
    // test_sort(heap_sort);
    // test_sort(bubble_sort);
    // test_sort(quick_sort);
    test_sort(merge_sort);

    return 0;
}


void TestOP()
{
    srand(time(0));
    const int N = 1000000;
    int* a1 = (int*)malloc(sizeof(int) * N);
    int* a2 = (int*)malloc(sizeof(int) * N);
    int* a3 = (int*)malloc(sizeof(int) * N);
    int* a4 = (int*)malloc(sizeof(int) * N);
    int* a5 = (int*)malloc(sizeof(int) * N);
    int* a6 = (int*)malloc(sizeof(int) * N);

    assert(a1 && a2 && a3 && a4 && a5 && a6);

    for (int i = 0; i < N; ++i)
    {
        a1[i] = rand();
        // a1[i] = i;
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
    }

	int begin1 = clock();
	// insert_sort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	shell_sort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	// select_sort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	// heap_sort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	quick_sort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	merge_sort(a6, N);
	int end6 = clock();

    printf("insert_sort: %d\n", end1 - begin1);
	printf("shell_sort : %d\n", end2 - begin2);
	printf("select_sort: %d\n", end3 - begin3);
	printf("heap_sort  : %d\n", end4 - begin4);
	printf("quick_sort : %d\n", end5 - begin5);
	printf("MergeSort :  %d\n", end6 - begin6);

	free(a6), free(a5), free(a4), free(a3), free(a2), free(a1);
}