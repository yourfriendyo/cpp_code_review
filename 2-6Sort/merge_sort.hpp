#pragma once
#include <iostream>
using namespace std;

void _merge_sort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
        return;

    int mid = (left + right) >> 1;
    // [left, mid] [mid+1, right]
    _merge_sort(a, left, mid, tmp);
    _merge_sort(a, mid + 1, right, tmp);

    int i = left;
    int i1 = left, i2 = mid + 1;
    while (i1 <= mid && i2 <= right)
        tmp[i++] = a[i1] < a[i2] ? a[i1++] : a[i2++];

    while (i1 <= mid)
        tmp[i++] = a[i1++];
    while (i2 <= right)
        tmp[i++] = a[i2++];

    memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void merge_sort(int* a, int n)
{
    int* tmp = new int[n];

    _merge_sort(a, 0, n - 1, tmp);

    delete tmp;
}
