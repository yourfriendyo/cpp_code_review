#pragma once
#include <iostream>
using namespace std;

void bubble_sort(int* a, int n)
{
    for (int j = 0; j < n; j++)
    {
        bool no_swap = true;

        for (int i = 1; i < n - j; i++)
        {
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                no_swap = false;
            }
        }
        if (no_swap)
            break;
    }
}

#if PARTITION == 1
int partition(int* a, int left, int right)
{

}

#elif PARTITION == 2
int partition(int* a, int left, int right)
{

}

#elif PARTITION == 3
int partition(int* a, int left, int right)
{

}
#endif

#ifdef NON_RECURSION == 0
void quick_sort(int* a, int left, int right)
{

}
#else
void quick_sort(int* a, int left, int right)
{

}
#endif

void quick_sort(int* a, int n) {
    quick_sort(a, 0, n - 1);
}