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

        swap(a[max_i], a[r]);
        swap(a[min_i], a[l]);
        l++, r--;
    }
}

void heap_sort(int* a, int n)
{

}