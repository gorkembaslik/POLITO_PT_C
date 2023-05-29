#include <stdio.h>
#define MAX 30

void subSequences(int v[], int n);

int main() {
    int v[MAX], n=0;

    while (n<MAX && scanf("%d", &v[n]) != 0) {
        // printf("v[%d]: %d\n", n, v[n]);
        n++;
    }
    subSequences(v, n);

    return 0;
}

void subSequences(int v[], int n) {
    int i, j, count;
    int o[MAX], x=0, y, max=0, a=0;
    for (i=0;i<n-1;i++) {
        if (v[i] == 0)
            continue;
        count =1;
        j=i+1;
        while (j<n && v[j] != 0) {
            count++;
            j++;
        }
        o[x++] = i;
        o[x++] = j-1;
        i=j;
    }
    for(y=0; y<x; y++) {
        if ((o[y+1]-o[y]) > max ) {
            max= o[y+1]-o[y];
        }
        y++;
    }
    for(int y=0; y<x; y++) {
        if ((o[y+1]-o[y]) == max ) {
            printf("[ ");
            while (o[y]<=o[y+1]) {
                printf("%d ", v[o[y]]);
                o[y]+=1;
            }
            printf("] ");
        }
        y++;
    }

}