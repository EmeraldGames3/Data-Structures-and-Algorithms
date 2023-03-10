#include "Swap.cpp"

#pragma once

template<typename type>
void bubbleSort(type *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
