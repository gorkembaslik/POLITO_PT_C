#include <stdio.h>
#define MAX 20

int main() {
    FILE *fin;
    char file[MAX];
    int i, j,n, m, matrix[MAX][MAX], max=0, index, temp,r;
    printf("filename: ");
    scanf("%s", file);

    if ((fin = fopen(file, "r")) == NULL) {
        printf("error opening file!!\n");
        return 1;
    }
    fscanf(fin,"%d %d", &n, &m);
    for (i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            fscanf(fin, "%d ", &matrix[i][j]);
            if (matrix[i][j] != 0 && matrix[i][j] != 1 && matrix[i][j] != 3) {
                printf("scores for each match can be only 0, 1 or 3!!\n");
                return 2;
            }
        }
    }
    for (j=0;j<m;j++) {
        temp=0;
        for (i=0;i<n;i++) {
            for(index=0;index<=j;index++) {
                max += matrix[i][index];
            }
            if (max > temp) {
                temp = max;
                r = i;
            }
            max=0;
        }
        printf("%d ", r);
    }
    return 0;
}