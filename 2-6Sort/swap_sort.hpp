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
    int keyi = left;
    while (left < right)
    {
        while (left < right && a[right] > a[keyi])
            right--;
        while (left < right && a[left] < a[keyi])
            left++;

        if (left < right)
            swap(a[left], a[right]);
    }

    swap(a[left], a[keyi]);
    return left;
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
    if (left >= right)
        return;

    int keyi = partition(a, left, right);
    quick_sort(a, left, keyi - 1);
    quick_sort(a, keyi + 1, right);
}
#else
void quick_sort(int* a, int left, int right)
{

}
#endif

void quick_sort(int* a, int n) {
    quick_sort(a, 0, n - 1);
}