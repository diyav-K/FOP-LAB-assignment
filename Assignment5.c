#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int i, j, k;

    // 1. Addition of two matrices
    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);
    int mat1[r1][c1];
    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);
    if (r1 != r2 || c1 != c2) {
        printf("Matrices can't be added (dimension mismatch).\n");
    } else {
        int mat2[r2][c2], sum[r1][c1];
        printf("Enter elements of second matrix:\n");
        for(i = 0; i < r2; i++)
            for(j = 0; j < c2; j++)
                scanf("%d", &mat2[i][j]);

        for(i = 0; i < r1; i++)
            for(j = 0; j < c1; j++)
                sum[i][j] = mat1[i][j] + mat2[i][j];

        printf("Sum of matrices:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++)
                printf("%d ", sum[i][j]);
            printf("\n");
        }
    }

    // 2. Saddle point of a matrix
    int r, c;
    printf("\nEnter rows and columns of matrix for saddle point: ");
    scanf("%d%d", &r, &c);
    int mat[r][c];
    printf("Enter elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    int saddle_found = 0;
    for(i = 0; i < r; i++) {
        int min_row = mat[i][0], col_index = 0;
        for(j = 1; j < c; j++) {
            if(mat[i][j] < min_row) {
                min_row = mat[i][j];
                col_index = j;
            }
        }
        int k;
        int is_saddle = 1;
        for(k = 0; k < r; k++) {
            if(mat[k][col_index] > min_row) {
                is_saddle = 0;
                break;
            }
        }
        if(is_saddle) {
            printf("Saddle point is %d at position (%d, %d)\n", min_row, i, col_index);
            saddle_found = 1;
        }
    }
    if(!saddle_found)
        printf("No saddle point found\n");

    // 3. Inverse of a matrix (only for 2x2 for simplicity)
    float det;
    printf("\nEnter 2x2 matrix to find inverse:\n");
    float matrix[2][2];
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%f", &matrix[i][j]);

    det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    if(det == 0)
        printf("Inverse not possible (determinant is zero)\n");
    else {
        float inverse[2][2];
        inverse[0][0] = matrix[1][1]/det;
        inverse[0][1] = -matrix[0][1]/det;
        inverse[1][0] = -matrix[1][0]/det;
        inverse[1][1] = matrix[0][0]/det;

        printf("Inverse matrix:\n");
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++)
                printf("%.2f ", inverse[i][j]);
            printf("\n");
        }
    }

    // 4. Magic square of size n (only odd n)
    int n;
    printf("\nEnter size of magic square (odd number): ");
    scanf("%d", &n);
    if(n % 2 == 0) {
        printf("Magic square is only possible for odd sizes\n");
    } else {
        int magic[n][n];
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                magic[i][j] = 0;

        int row = 0, col = n/2, num;
        for(num = 1; num <= n*n; ) {
            if(row < 0 && col == n) {
                row = 0; col = n-2;
            } else {
                if(col == n)
                    col = 0;
                if(row < 0)
                    row = n-1;
            }
            if(magic[row][col] != 0) {
                row += 1;
                col -= 2;
                continue;
            } else {
                magic[row][col] = num++;
            }
            row--; col++;
        }
        printf("Magic square of size %d:\n", n);
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++)
                printf("%3d ", magic[i][j]);
            printf("\n");
        }
    }

    return 0;
}