 #include <stdio.h>

int main() {
    int row1, col1, row2, col2;
    int A[10][10], B[10][10];
    int sp_mat1[100][3], sp_mat2[100][3], sp_sum[100][3];
    int i, j, k = 1, u = 1, h = 1;

    printf("Enter the row size of the first matrix: ");
    scanf("%d", &row1);
    printf("Enter the column size of the first matrix: ");
    scanf("%d", &col1);

    printf("Enter the row size of the second matrix: ");
    scanf("%d", &row2);
    printf("Enter the column size of the second matrix: ");
    scanf("%d", &col2);


    if (row1 != row2 || col1 != col2) {
        printf("Matrix dimensions do not match. Cannot perform addition.\n");
        return 0;
    }

    
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Enter the elements:");
            scanf("%d", &A[i][j]);
        }
    }

 
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Enter the elements:");
            scanf("%d", &B[i][j]);
        }
    }

  
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            if (A[i][j] != 0) {
                sp_mat1[k][0] = i;
                sp_mat1[k][1] = j;
                sp_mat1[k][2] = A[i][j];
                k++;
            }
        }
    }
    sp_mat1[0][0] = row1;
    sp_mat1[0][1] = col1;
    sp_mat1[0][2] = k - 1;

    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            if (B[i][j] != 0) {
                sp_mat2[u][0] = i;
                sp_mat2[u][1] = j;
                sp_mat2[u][2] = B[i][j];
                u++;
            }
        }
    }
    sp_mat2[0][0] = row2;
    sp_mat2[0][1] = col2;
    sp_mat2[0][2] = u - 1;

   
    int p = 1, q = 1;
    while (p <= sp_mat1[0][2] && q <= sp_mat2[0][2]) {
        if (sp_mat1[p][0] < sp_mat2[q][0] ||
           (sp_mat1[p][0] == sp_mat2[q][0] && sp_mat1[p][1] < sp_mat2[q][1])) {
            sp_sum[h][0] = sp_mat1[p][0];
            sp_sum[h][1] = sp_mat1[p][1];
            sp_sum[h][2] = sp_mat1[p][2];
            h++; p++;
        } else if (sp_mat2[q][0] < sp_mat1[p][0] ||
                  (sp_mat2[q][0] == sp_mat1[p][0] && sp_mat2[q][1] < sp_mat1[p][1])) {
            sp_sum[h][0] = sp_mat2[q][0];
            sp_sum[h][1] = sp_mat2[q][1];
            sp_sum[h][2] = sp_mat2[q][2];
            h++; q++;
        } else {
            int summed_value = sp_mat1[p][2] + sp_mat2[q][2];
            if (summed_value != 0) {
                sp_sum[h][0] = sp_mat1[p][0];
                sp_sum[h][1] = sp_mat1[p][1];
                sp_sum[h][2] = summed_value;
                h++;
            }
            p++; q++;
        }
    }

    
    while (p <= sp_mat1[0][2]) {
        sp_sum[h][0] = sp_mat1[p][0];
        sp_sum[h][1] = sp_mat1[p][1];
        sp_sum[h][2] = sp_mat1[p][2];
        h++; p++;
    }
    while (q <= sp_mat2[0][2]) {
        sp_sum[h][0] = sp_mat2[q][0];
        sp_sum[h][1] = sp_mat2[q][1];
        sp_sum[h][2] = sp_mat2[q][2];
        h++; q++;
    }

   
    sp_sum[0][0] = row1;
    sp_sum[0][1] = col1;
    sp_sum[0][2] = h - 1;

    
    printf("\nResultant Sparse Matrix2:\n");
    printf("Row\tCol\tVal\n");
    for (i = 0; i < h; i++) {
        printf("%d\t%d\t%d\n", sp_sum[i][0], sp_sum[i][1], sp_sum[i][2]);
    }

    return 0;
}
