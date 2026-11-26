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