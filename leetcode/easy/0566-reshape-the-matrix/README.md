# Reshape the Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

In MATLAB, there is a handy function called `reshape` which can reshape an `m x n` matrix into a new one with a different size `r x c` keeping its original data.

You are given an `m x n` matrix `mat` and two integers `r` and `c` representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the `reshape` operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Original
C
 **Example 1:** 

```
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

```

 **Example 2:** 

```
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

```

 

 **Constraints:** 

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 100
- -1000 <= mat[i][j] <= 1000
- 1 <= r, c <= 300

## Solution

**Language:** C  
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-11-26T13:18:15.121Z  

```c
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = (m > 0 && matColSize != NULL) ? matColSize[0] : 0;

    if (m <= 0 || n <= 0 || r <= 0 || c <= 0 || m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc((size_t)m * sizeof(int));
        int** original = (int**)malloc((size_t)m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            (*returnColumnSizes)[i] = n;
            original[i] = (int*)malloc((size_t)n * sizeof(int));
            for (int j = 0; j < n; j++) {
                original[i][j] = mat[i][j];
            }
        }
        return original;
    }

    *returnSize = r;
    *returnColumnSizes = (int*)malloc((size_t)r * sizeof(int));
    int** reshaped = (int**)malloc((size_t)r * sizeof(int*));

    int total = m * n;
    for (int idx = 0; idx < total; idx++) {
        int newRow = idx / c;
        int newCol = idx % c;
        if (newCol == 0) {
            (*returnColumnSizes)[newRow] = c;
            reshaped[newRow] = (int*)malloc((size_t)c * sizeof(int));
        }
        int oldRow = idx / n;
        int oldCol = idx % n;
        reshaped[newRow][newCol] = mat[oldRow][oldCol];
    }

    return reshaped;
}
```

---

[View on LeetCode](https://leetcode.com/problems/reshape-the-matrix/)