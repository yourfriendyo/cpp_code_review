#pragma once
#include <iostream>
using namespace std;

void _merge_sort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    _merge_sort(a, left, mid, tmp);
    _merge_sort(a, mid + 1, right, tmp);
    // [left, mid][mid+1, right]

    int i1 = left, i2 = mid + 1;
    int i = left;
    while (i1 <= mid && i2 <= right)
        tmp[i++] = a[i1] <= a[i2] ? a[i1++] : a[i2++];
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

    delete[] tmp;
}

void merge_sort_non_r(int* a, int n)
{
    int* tmp = new int[n];

    int range = 1;
    while (range < n)
    {
        for (int i = 0; i < n; i += 2 * range)
        {
            // [i, i+r-1] [i+r, i+2*r-1]
            int b1 = i, b2 = i + range;
            int e1 = i + range - 1, e2 = i + 2 * range - 1;

            if (e1 >= n)
                break;
            else if (b2 >= n)
                break;
            else if (e2 >= n)
                e2 = n - 1;

            int j = i;
            while (b1 <= e1 && b2 <= e2)
                tmp[j++] = a[b1] <= a[b2] ? a[b1++] : a[b2++];
            while (b1 <= e1)
                tmp[j++] = a[b1++];
            while (b2 <= e2)
                tmp[j++] = a[b2++];

            memcpy(a + i, tmp + i, sizeof(int) * (j - i));
        }

        range *= 2;
    }

    delete[] tmp;
}