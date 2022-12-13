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

    delete[] tmp;
}

void merge_sort_non_r(int* a, int n)
{
    int* tmp = new int[n];

    int ranger = 1;
    while (ranger < n)
    {
        for (int i = 0; i < n; i += ranger * 2)
        {
            // [i, i+rgr-1] [i+rgr, i+rgr*2-1]
            int b1 = i, b2 = i + ranger;
            int e1 = i + ranger - 1, e2 = i + 2 * ranger - 1;

            if (e1 >= n) {
                e1 = n-1;
                b2 = n, e2 = n - 1;
            }
            else if (b2 >= n) {
                b2 = n, e2 = n - 1;
            }
            else if (e2 >= n) {
                e2 = n - 1;
            }

            int j = i;
            while (b1 <= e1 && b2 <= e2)
                tmp[j++] = a[b1] < a[b2] ? a[b1++] : a[b2++];

            while (b1 <= e1)
                tmp[j++] = a[b1++];
            while (b2 <= e2)
                tmp[j++] = a[b2++];

            memcpy(a + i, tmp + i, sizeof(int) * (e2 - i + 1));
        }
        ranger *= 2;
    }

    delete[] tmp;
}
