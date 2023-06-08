#include <stdio.h>
#define MAX_RC 50

typedef struct {
    int height, width, area;
    int x, y;
} rectangle;


int main() {
    FILE *fp;
    int nr, nc, i, j, found=0, height, width, area, x,y, max_w=0, max_a=0, max_h=0;
    int matrix[MAX_RC][MAX_RC];
    rectangle rect[MAX_RC];

    fp = fopen("../input.txt", "r");
    if (fp == NULL)
        return 1;
    fscanf(fp, "%d %d", &nr, &nc);
    for (i=0;i<nr;i++){
        for (j=0;j<nc;j++){
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    fclose(fp);
    for (i=0;i<nr;i++){
        for (j=0;j<nc;j++){
            int a=1, b=1;
            if (matrix[i][j] == 1) {
                rect[found].x=i; rect[found].y=j;
                height=1; width=1; area=1;
                while (matrix[i][j+b] == 1 && j<nc) {
                    width++;
                    area++;
                    b++;
                }
                while (matrix[i+a][j] == 1 && i<nr) {
                    height++;
                    area++;
                    a++;
                }
                if (a != 1 && b != 1) {
                    for (x=1;x<a;x++) {
                        for (y=1;y<b;y++) {
                            if (matrix[i+x][j+y] == 1)
                                area++;
                            else {
                                printf("format error found, not rectangular shape!!\n");
                                return 2;
                            }
                        }
                    }
                }
                rect[found].area = area;
                rect[found].height = height;
                rect[found].width = width;
                j= j+b-1;
                found++;
            }
        }
    }
    for (i=0;i<=found;i++) {
        if (rect[i].area>rect[max_a].area)
            max_a=i;
        if (rect[i].width>rect[max_w].area)
            max_w=i;
        if (rect[i].height>rect[max_h].area)
            max_h=i;
    }
    printf("Max-height region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n", rect[max_h].x, rect[max_h].y, rect[max_h].height, rect[max_h].width, rect[max_h].area);
    printf("Max-width region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n", rect[max_w].x, rect[max_w].y, rect[max_w].height, rect[max_w].width, rect[max_w].area);
    printf("Max-area region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n", rect[max_a].x, rect[max_a].y, rect[max_a].height, rect[max_a].width, rect[max_a].area);

    return 0;
}