#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "insert_sort.hpp"
#include "select_sort.hpp"
#include "swap_sort.hpp"
#include "merge_sort.hpp"
#include "nocmp_sort.hpp"

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
    int a[] = { 8,3,0,7,2,9,1,6,4,5 };
    int n = sizeof(a) / sizeof(int);

    print_arr(a, n);
    sort(a, n);
    print_arr(a, n);
}

int main()
{
    // test_sort(insert_sort);
    // test_sort(shell_sort);
    // test_sort(shell_sort_simp);
    test_sort(select_sort);


    return 0;
}