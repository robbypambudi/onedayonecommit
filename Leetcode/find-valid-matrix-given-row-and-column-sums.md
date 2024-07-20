# Find Valid Matrix Given Row and Column Sums

## Problem
[Find Valid Matrix Given Row and Column Sums](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)

## Approach
> Using Greedy Approach

1. Find the size of the matrix.
2. Declare a matrix of size `N x M` with all elements initialized to `0`.
3. Initialize two variables `i` and `j` to `0`, this will be used to traverse the matrix.
4. Iterate over the matrix until `i < N` and `j < M`.
5. Find the minimum of `rowSum[i]` and `colSum[j]` and assign it to the matrix at position `i, j`.
6. Subtract the assigned value from `rowSum[i]` and `colSum[j]`.
7. If `rowSum[i]` is `0`, increment `i` else increment `j`.
8. Return the matrix.

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));

        int i = 0, j = 0;
        while(i < N && j < M){
            origMatrix[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= origMatrix[i][j];
            colSum[j] -= origMatrix[i][j];

            rowSum[i] == 0 ? i++ : j++;
        }
        return origMatrix;
    }
};
```

## References
[LeetCode - Find Valid Matrix Given Row and Column Sums](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)