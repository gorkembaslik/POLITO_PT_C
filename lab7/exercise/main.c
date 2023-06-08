#include <stdio.h>
#define MAX_ROW 600
#define MAX_COL 800
#define MAX_LINE 100

typedef struct {
    int r2, r1, c2, c1;
    int color, level;
} t_rectangle;

int matrix[MAX_ROW][MAX_COL];
t_rectangle rectangle[MAX_LINE];

void colorPixel(int nr, FILE *fp);
void writeRectangle(FILE *fp, int i);

int main(int argc, char *argv[]) {
    FILE *file;
    int r, c, r1, r2, c1, c2;
    int color, level, i;
    char line[MAX_LINE];

    file = fopen(argv[1], "r");

    if (file==NULL)
        return 1;

    for (r=0; r<MAX_ROW; r++) {
        for (c=0; c<MAX_COL; c++) {
            matrix[r][c] = -1;
        }
    }

    for (i=0;fgets(line, MAX_LINE, file)!=NULL;i++){
        switch (line[0]) {
            case 'p': case 'P':
                sscanf(line, "%*c %d %d %d %d", &r1, &c1, &color, &level);
                r2 = r1; c2= c1;
                break;
            case 'r': case 'R':
                sscanf(line, "%*c %d %d %d %d %d %d", &r1, &r2, &c1, &c2, &color, &level);
                break;
        }
        rectangle[i].r1=r1; rectangle[i].r2=r2;
        rectangle[i].c1=c1; rectangle[i].c2=c2;
        rectangle[i].color=color;
        rectangle[i].level=level;
    }
    int nr= i;
    fclose(file);
    file = fopen(argv[2], "w");
    if (file == NULL)
        return 2;
    colorPixel(nr, file);

    return 0;
}

void colorPixel(int nr, FILE* fp) {
    int i, level, p, r, c;

    for(i=0; i<nr; i++) {
        for(r=rectangle[i].r1;r<rectangle[i].r2;r++) {
            for(c=rectangle[i].c1;c<rectangle[i].c2;c++) {
                p = matrix[r][c];
                level = rectangle[i].level;
                if (p<0 || level > rectangle[p].level) {
                    matrix[r][c] = i;
                    writeRectangle(fp, i);
                }
            }
        }
    }
}

void writeRectangle(FILE *fp, int i){
    int r1,r2,c1,c2;

    r1=rectangle[i].r1; r2=rectangle[i].r2;
    c1=rectangle[i].c1; c2=rectangle[i].c2;
    if (r1==r2 && c1==c2)
        fprintf(fp, "p %d %d", r1, c1);
    else
        fprintf(fp, "p %d %d %d %d", r1, r2, c1, c2);
    fprintf(fp, " %d %d", rectangle[i].level, rectangle[i].color);
}