#include <stdio.h>
#include <string.h>
#define MAX 200

int main() {
    FILE *fsin, *fdin, *fout;
    char line[MAX], lined[2][10], *p, arr[MAX], tempa[MAX];
    int i, j, r, x;

    if ((fsin = fopen("../source.txt", "r")) == NULL) {
        printf("problem opening source file!!\n");
        return 1;
    }
    if ((fdin = fopen("../dictionary.txt", "r")) == NULL) {
        printf("problem opening dictionary file!!\n");
        return 2;
    }
    if ((fout = fopen("../output.txt", "w")) == NULL) {
        printf("problem opening output file!!\n");
        return 3;
    }
    while (!feof(fsin)) {
        fgets(line, MAX, fsin);
        fscanf(fdin,"%d", &r);
        for (i=1;i<=r && i<=30;i++) {
            fscanf(fdin,"%s %s", lined[0], lined[1]);
            while (1) {
                p = strstr(line, lined[1]);
                if (p) {
                    for (x= strlen(lined[1]), j=0; x< strlen(line);j++,x++) {
                        arr[j] = p[x];
                    }
                    strcpy(tempa, lined[0]);
                    strcat(tempa, arr);
                    strcpy(p,tempa);
                }
                else
                    break;
            }
        }
        fprintf(fout,"%s", line);
        rewind(fdin);
    }
    fclose(fsin);
    fclose(fdin);
    fclose(fout);
    return 0;
}