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