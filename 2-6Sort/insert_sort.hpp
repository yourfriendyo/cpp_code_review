#pragma once
#include <iostream>
using namespace std;


void insert_sort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int end = i;
        int x = a[end + 1];

        while (end >= 0)
        {
            if (a[end] > x)
                a[end + 1] = a[end];
            else
                break;

            --end;
        }

        a[end + 1] = x;
    }
}

void shell_sort(int* a, int n)
{
    int gap = n;
    while (gap > 0)
    {
        gap /= 2;
        for (int j = 0; j < gap; j++)
        {
            for (int i = j; i < n - gap; i += gap)
            {
                int end = i;
                int x = a[end + gap];

                while (end >= 0)
                {
                    if (a[end] > x)
                        a[end + gap] = a[end];
                    else
                        break;

                    end -= gap;
                }

                a[end + gap] = x;
            }
        }
    }
}

void shell_sort_simp(int* a, int n)
{
    int gap = n;
    while (gap > 0)
    {
        gap /= 2;
        for (int i = 0; i < n - gap; i++)
        {
            int end = i;
            int x = a[end + gap];

            while (end >= 0)
            {
                if (a[end] > x)
                    a[end + gap] = a[end];
                else
                    break;
                end -= gap;
            }

            a[end + gap] = x;
        }
    }
}