/*For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.*/

#include <bits/stdc++.h>
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{

    vector<int> ans;

    for (int col = 0; col < mCols; col++)
    {

        if (col & 1)
        {
            // odd

            for (int row = nRows - 1; row >= 0; row--)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else
        {
            // even

            for (int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}
