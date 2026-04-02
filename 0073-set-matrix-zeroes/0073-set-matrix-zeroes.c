void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int* rows = calloc(matrixSize, sizeof(int));
    int* cols = calloc(*matrixColSize, sizeof(int));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = 16;
                cols[j] = 16;
            }
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        if (rows[i] == 16) {
            for (int j = 0; j < *matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < *matrixColSize; j++) {
        if (cols[j] == 16) {
            for (int i = 0; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    free(rows);
    free(cols);
}