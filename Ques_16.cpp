/*Given a sequence of numbers ‘ARR’. Your task is to return a sorted sequence of
 ‘ARR’ in non-descending order with help of the merge sort algorithm.*/

void merge(vector<int> &arr, int s, int mid, int e)
{

    int n1 = mid - s + 1;
    int n2 = e - mid;

    int *left = new int[n1];
    int *right = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[s + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0;
    int k = s;

    while (i < n1 && j < n2)
    {

        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void solve(vector<int> &arr, int s, int e)
{

    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;
    solve(arr, s, mid);
    solve(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

void mergeSort(vector<int> &arr, int n)
{
    solve(arr, 0, n - 1);
}
