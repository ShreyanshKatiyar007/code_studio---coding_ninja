/*You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.*/

#include <iostream>
using namespace std;

int firstoccurrence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = start + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastoccurrence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = start + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int arr[5] = {1, 3, 7, 7, 11};
    int key;
    cout << "Enter the element to check the occurrence:";
    cin >> key;
    cout << "First occurrence of element is at index " << firstoccurrence(arr, 5, key) << endl;
    cout << "last occurrence of element is at index " << lastoccurrence(arr, 5, key);
}
