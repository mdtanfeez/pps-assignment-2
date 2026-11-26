# Transpose Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a 2D integer array `matrix`, return  *the  **transpose**  of*  `matrix`.

The  **transpose**  of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

 

Original
C
 **Example 1:** 

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

```

 **Example 2:** 

```
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

```

 

 **Constraints:** 

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- -109 <= matrix[i][j] <= 109

## Solution

**Language:** C  
**Runtime:** 1 ms (beats 8.98%)  
**Memory:** 16.1 MB (beats 13.89%)  
**Submitted:** 2026-11-26T13:17:19.970Z  

```c
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = (rows > 0 && matrixColSize != NULL) ? matrixColSize[0] : 0;

    *returnSize = cols;
    *returnColumnSizes = (int*)malloc((size_t)cols * sizeof(int));
    int** result = (int**)malloc((size_t)cols * sizeof(int*));

    for (int c = 0; c < cols; c++) {
        (*returnColumnSizes)[c] = rows;
        result[c] = (int*)malloc((size_t)rows * sizeof(int));
        for (int r = 0; r < rows; r++) {
            result[c][r] = matrix[r][c];
        }
    }

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/transpose-matrix/)