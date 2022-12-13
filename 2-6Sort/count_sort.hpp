#pragma once
#include <iostream>
using namespace std;

void count_sort(int* a, int n)
{
    int max = a[0], min = a[0];

    for (int i = 0; i < n; i++)
    {
        max = std::max(max, a[i]);
        min = std::min(min, a[i]);
    }

    int range = max - min + 1;
    int* count = new int[range];
    memset(count, 0, sizeof(int) * range);

    for (int i = 0; i < n; i++)
        count[unsigned int(a[i] - min)]++;

    int pos = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i]--)
            a[pos++] = i + min;
    }
}
