#include <stdio.h>
#include <string.h>

#define MAX 31

void row_rotate (int matrix[][MAX], int index, char direction[], int locations, int nc);
void column_rotate (int matrix[][MAX], int index, char direction[], int locations, int nr);

int main() {
    FILE *fin;
    char file[21], command[100], selector[7], direction[6];
    int matrix[MAX][MAX], nc, nr, i, j, index, locations;

    printf("File name: ");
    scanf("%s", file);

    if ((fin= fopen(file, "r")) == NULL)
        return 1;
    fscanf(fin,"%d %d", &nr, &nc);

    for (i=0;i<nr && i<MAX;i++) {
        for (j=0; j<nc && j<MAX; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }
    while (1) {
        fgets(command, 100, stdin);
        sscanf(command, "%s %d %s %d", selector, &index, direction, &locations);

        if (locations>0) {
            if (strcmp(selector, "end") == 0)
                break;
            else if (strcmp(selector, "row") == 0) {
                if (index<1 || index>nr) {
                    printf("wrong index\n");
                    return 3;
                }
                row_rotate(matrix, index, direction, locations, nc);
            }
            else if (strcmp(selector, "column") == 0) {
                if (index<1 || index>nc) {
                    printf("wrong index\n");
                    return 4;
                }
                column_rotate(matrix, index, direction, locations, nr);
            }
            else {
                printf("selector is not valid, it should be ""row"" or ""column""!!");
                return 2;
            }
        }

        for (i=0;i<nr;i++) {
            for (j=0; j<nc; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    fclose(fin);
    return 0;
}

void row_rotate (int matrix[][MAX], int index, char direction[6], int locations, int nc) {
    int temp[nc], j;
    index -=1;
    if (locations>nc)
        locations-=nc;

    if (strcmp(direction, "right")==0) {
        for (j=0;j<nc;j++)
            temp[ (j+locations) % nc] = matrix[index][j];

        for (j=0;j<nc;j++)
            matrix[index][j] = temp[j];
    }
    else if (strcmp(direction, "left")==0) {
        locations = nc-locations;
        for (j=0;j<nc;j++)
            temp[ (j+locations) % nc] = matrix[index][j];

        for (j=0;j<nc;j++)
            matrix[index][j] = temp[j];
    }
    else {
        printf("\nwrong direction to rotate row, should be right or left");
    }
}

void column_rotate (int matrix[MAX][MAX], int index, char direction[6], int locations, int nr) {
    int temp[nr], i;
    index -=1;
    if (locations>nr)
        locations-= nr;

    if (strcmp(direction, "down")==0) {
        for (i=0;i<nr;i++) {
            temp[(i+locations) % nr] = matrix[i][index];
        }

        for (i=0;i<nr;i++) {
            matrix[i][index] = temp[i];
        }
    }
    else if (strcmp(direction, "up")==0) {
        locations = nr-locations;
        for (i=0;i<nr;i++) {
            temp[(i+locations) % nr] = matrix[i][index];
        }

        for (i=0;i<nr;i++) {
            matrix[i][index] = temp[i];
        }
    }
    else
        printf("\nwrong direction, it should be up or down");
}