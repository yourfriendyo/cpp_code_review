#pragma once
#include <iostream>
using namespace std;

void select_sort(int* a, int n)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int max_i = l;
        int min_i = l;
        for (int i = l; i <= r; i++)
        {
            if (a[i] > a[max_i])
                max_i = i;
            if (a[i] < a[min_i])
                min_i = i;
        }

        swap(a[min_i], a[l]);
        if (max_i == l)
            max_i = min_i; // 交换中意外修改max元素位置 修正
        swap(a[max_i], a[r]);

        l++, r--;
    }
}

void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;

    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
            child++;

        if (a[child] > a[parent])
            swap(a[child], a[parent]);
        else
            break;

        parent = child;
        child = parent * 2 + 1;
    }
}
void heap_sort(int* a, int n)
{
    for (int i = (n - 2) / 2; i >= 0; --i)
        AdjustDown(a, n, i);

    for (int i = n - 1; i > 0; --i)
    {
        swap(a[0], a[i]);
        AdjustDown(a, i, 0);
    }
}