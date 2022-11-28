#pragma once
#include <iostream>
using namespace std;


void insert_sort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++) // end最后是n-1位置
    {
        int end = i;
        int x = a[end + 1]; // end后一个元素作待插元素

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

void shell_sort(int* a , int n)
{
    int gap = n;
    while (gap > 1) // gap不断减小分组预排多次
    {
        gap = gap / 3 + 1; // 保证最后一定gap=1执行最后一次直接插排

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
    while (gap > 1)
    {
        gap = gap / 3 + 1;

        for (int i = 0; i < n - gap; i++) // 多组同时排
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