#pragma once
#include <iostream>
using namespace std;

void select_sort(int* a, int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int mini = left;
        int maxi = left;
        for (int i = left; i <= right; i++)
        {
            if (a[i] < a[mini]) mini = i;
            if (a[i] > a[maxi]) maxi = i;
        }

        swap(a[left], a[mini]);
        if (left == maxi)
            maxi = mini;
        swap(a[right], a[maxi]);

        left++, right--;
    }
}

void adjust_down(int* a, int n, int parent)
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
    for (int i = (n - 2) / 2; i >= 0; i--)
        adjust_down(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        adjust_down(a, i, 0);
    }
}