#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define FILE_NAME "../numbers.txt"
#define MAX 50

int main() {
    FILE *fin;
    int a[MAX],count=0, i,j, discarded=0, flag=0;

    if ((fin= fopen(FILE_NAME, "r")) == NULL) {
        printf("Problem with opening file\n");
        return 0;
    }

    while(!feof(fin)) {
        fscanf(fin, "%d", &a[count]);
        count +=1;
    }
    int max= a[0], min= a[0];

    for (i=0;i<count;i++) {
        printf("%d\n", a[i]);
        if (i>=2) {
            if (a[i - 2] + a[i - 1] == a[i] || (a[i - 2] - a[i - 1] == a[i]) || (a[i - 2] * a[i - 1] == a[i])) {}
            else if (a[i - 1] != 0) {
                if (a[i - 2] / a[i - 1] != a[i]) {
                    flag = 1;
                    discarded += 1;
                }
            } else {
                flag = 1;
                discarded += 1;
            }

            if (flag == 1) {
                count -= 1;
                j = i;
                for (; j < count; j++) {
                    a[j] = a[j + 1];
                }
                i--;
                flag = 0;
            }
            if (i>0) {
                if (a[i]>max) {
                    max = a[i];
                }
                if (a[i]<min) {
                    min = a[i];
                }
            }
        }
    }

    printf("# of discarded values: %d\nMaximum value: %d\nMinimum value: %d\n", discarded, max, min);

    return 0;
}
