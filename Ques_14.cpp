/*You are given an integer array 'A' of size 'N', sorted in non-decreasing order. You are also given an integer 'target'.
Your task is to write a function to search for 'target' in the array 'A'. If it exists, return its index in 0-based indexing.
If 'target' is not present in the array 'A', return -1.*/

int BinarySearch(vector<int> &nums, int s, int e, int key)
{

    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;

    if (nums[mid] == key)
    {
        return mid;
    }

    if (nums[mid] < key)
    {
        return BinarySearch(nums, mid + 1, e, key);
    }
    else
    {
        return BinarySearch(nums, s, mid - 1, key);
    }
}

int search(vector<int> &nums, int target)
{
    int ans = BinarySearch(nums, 0, nums.size() - 1, target);
}
