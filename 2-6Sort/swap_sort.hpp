#pragma once
#include <iostream>
#include <stack>
using namespace std;

void bubble_sort(int* a, int n)
{
    for (int j = 0; j < n; j++)
    {
        int no_swap = true;

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
#define PART 3
#if PART == 1
void quick_sort(int* a, int left, int right)
{
    if (left >= right)
        return;

    int i = left, j = right;
    int k = i;

    while (i < j)
    {
        while (i < j && a[j] >= a[k])
            j--;
        while (i < j && a[i] <= a[k])
            i++;
        swap(a[i], a[j]);
    }
    swap(a[i], a[k]);

    quick_sort(a, left, i - 1);
    quick_sort(a, i + 1, right);
}

#elif PART == 2
void quick_sort(int* a, int left, int right)
{
    if (left >= right)
        return;

    int i = left, j = right;

    int key = a[i];
    int pivot = i;
    while (i < j)
    {
        while (i < j && a[j] >= key)
            j--;
        a[pivot] = a[j];
        pivot = j;

        while (i < j && a[i] <= key)
            i++;
        a[pivot] = a[i];
        pivot = i;
    }
    a[pivot] = key;

    quick_sort(a, left, pivot - 1);
    quick_sort(a, pivot + 1, right);
}

#else
void quick_sort(int* a, int left, int right)
{
    if (left >= right)
        return;

    int i = left, j = right;

    int keyi = i;
    int cur = i + 1, prev = cur - 1;
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && (++prev != cur))
            swap(a[cur], a[prev]);
        cur++;
    }
    swap(a[prev], a[keyi]);

    quick_sort(a, left, prev - 1);
    quick_sort(a, prev + 1, right);
}
#endif


void quick_sort_non_r(int* a, int left, int right)
{
    stack<pair<int, int>> s;
    s.push({ left, right });

    while (!s.empty())
    {
        auto idx = s.top();
        s.pop();
        int l = idx.first, r = idx.second;

        int i = l, j = r;
        int k = i;
        while (i < j)
        {
            while (i < j && a[j] >= a[k])
                j--;
            while (i < j && a[i] <= a[k])
                i++;
            swap(a[i], a[j]);
        }
        swap(a[i], a[k]);

        if (i + 1 < r)
            s.push({ i + 1, r });
        if (l < i - 1)
            s.push({ l, i - 1 });
    }
}

void quick_sort(int* a, int n)
{
    // quick_sort(a, 0, n - 1);
    quick_sort_non_r(a, 0, n - 1);
}