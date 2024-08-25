/*You are given an array of integers. You need to sort the array in ascending order using quick sort.

Quick sort is a divide and conquer algorithm in which we choose a pivot point and partition the array into two parts
i.e, left and right. The left part contains the numbers smaller than the pivot element and the right part contains
the numbers larger than the pivot element. Then we recursively sort the left and right parts of the array.*/

#include <bits/stdc++.h>

int partition(vector<int> &arr, int s, int e)
{

    int pivot = arr[s];

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void solve(vector<int> &arr, int s, int e)
{

    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    solve(arr, s, p - 1);
    solve(arr, p + 1, e);
}

vector<int> quickSort(vector<int> arr)
{
    solve(arr, 0, arr.size() - 1);
    return arr;
}
