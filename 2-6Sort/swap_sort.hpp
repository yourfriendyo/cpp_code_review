#pragma once
#include <iostream>
#include <stack>
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

#define PARTITION 3
#define THREE_WAYS 1

#if PARTITION == 1
int partition(int* a, int left, int right)
{
    int keyi = left;
    while (left < right)
    {
        while (left < right && a[right] >= a[keyi])
            right--;
        while (left < right && a[left] <= a[keyi])
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
    int key = a[left];
    int pivot = left;

    while (left < right)
    {
        while (left < right && a[right] >= key)
            --right;
        a[pivot] = a[right];
        pivot = right;

        while (left < right && a[left] <= key)
            ++left;
        a[pivot] = a[left];
        pivot = left;
    }

    a[pivot] = key;
    return pivot;
}

#elif PARTITION == 3
int partition(int* a, int left, int right)
{
    int keyi = left;
    int prev = left, cur = left + 1;

    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
            swap(a[prev], a[cur]);

        ++cur;
    }

    swap(a[keyi], a[prev]);
    return prev;
}
#endif

int select_mid(int* a, int left, int right)
{
    int mid = left + ((right - left) >> 1);
    if (a[left] < a[right])
    {
        if (a[mid] < a[left])
            return left;
        else if (a[mid] < a[right])
            return mid;
        else
            return right;
    }
    else
    {
        if (a[mid] > a[left])
            return left;
        else if (a[mid] > a[right])
            return mid;
        else
            return right;
    }
}

void quick_sort(int* a, int left, int right)
{
    if (left >= right)
        return;

    if (right - left < 10) {
        insert_sort(a + left, right - left + 1);
        return;
    }

    int midi = select_mid(a, left, right);
    swap(a[left], a[midi]);

    int keyi = partition(a, left, right);
    quick_sort(a, left, keyi - 1);
    quick_sort(a, keyi + 1, right);
}

void quick_sort_non_r(int* a, int left, int right)
{
    stack<int> s;
    s.push(left);
    s.push(right);

    while (!s.empty())
    {
        int end = s.top();
        s.pop();
        int bgn = s.top();
        s.pop();

        int keyi = partition(a, bgn, end);

        if (keyi + 1 < end)
        {
            s.push(keyi + 1);
            s.push(end);
        }
        if (bgn < keyi - 1)
        {
            s.push(bgn);
            s.push(keyi - 1);
        }
    }
}

#define NON_RECURSION 1

void quick_sort(int* a, int n)
{
#ifndef NON_RECURSION
    quick_sort(a, 0, n - 1);
#else
    quick_sort_non_r(a, 0, n - 1);
#endif
}