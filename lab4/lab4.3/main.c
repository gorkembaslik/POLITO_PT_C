#include <stdio.h>
#define MAX 20

int main() {
    FILE *fin;
    char file_name[20];
    int i, j, x, y, nr, nc, matrix[MAX][MAX], min, max_sum, max_row, max_col, temp, dim;
    printf("type name of the file: \n");
    scanf("%s", file_name);

    if ((fin = fopen(file_name,"r")) == NULL)
        return 1;

    fscanf(fin,"%d %d", &nr, &nc);

    for(i=0;i<nr;i++) {
        for(j=0; j<nc; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }
    min=nr;
    if (nc<nr)
        min=nc;

    while(1) {
        printf("dimension of matrix? (between 1 and %d): ", min);
        scanf("%d", &dim);

        if (dim<=1 || dim>nc) {
            printf("\ndimension is wrong!!");
            break;
        }

        for (i=0; i<=nr-dim; i++) {
            for (j=0; j<=nc-dim; j++) {
                temp=0;
                for(x=0; x<dim;x++) {
                    for(y=0;y<dim;y++) {
                        printf("%d ", matrix[i+x][j+y]);
                        temp+= matrix[i+x][j+y];
                    }
                    printf("\n");
                }
                printf("\n");
                if (temp>max_sum) {
                    max_sum = temp;
                    max_row = i;
                    max_col = j;
                }
            }
        }
        printf("The sub-matrix with maximum sum of elements (%d) is:\n", max_sum);
        for (i = max_row; i<max_row+dim;i++) {
            for (j=max_col; j<max_col+dim;j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    fclose(fin);
    return 0;
}
