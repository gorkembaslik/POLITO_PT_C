#include <stdio.h>
#define maxN 30

void rotate(int v[], int n, int p, int dir);

int main() {
    int a=0, n, v[maxN], p, dir;

    printf("amount of integers: ");
    scanf("%d", &n);

    printf("\nthe values: ");
    while (a<n) {
        scanf("%d", &v[a]);
        a++;
    }

    while (1) {
        printf("\nhow many of positions to switch?: ");
        scanf("%d", &p);
        if (p==0) {
            printf("process terminated upon the request..");
            break;
        }
        else if (p<n) {
            printf("\nwhich direction? (-1 for right and 1 for left): ");
            scanf("%d", &dir);
            rotate(v, n, p, dir);
        }
        else {
            printf("\nwrite a value less than number of elements!!\n");
        }
    }
    return 0;
}

void rotate(int v[], int n, int p, int dir) {
    int a=0, temp[n], i;

        if (dir == -1) {
            //right
            for (i = 0; i < n; i++) {
                temp[(i + p) % n] = v[i];
            }

            // Copy elements of temp back to v
            for (i = 0; i < n; i++) {
                v[i] = temp[i];
            }
        }
        else if ( dir == 1 ) {
            //left
            p= n-p;
            for (i = 0; i < n; i++) {
                temp[(i + p) % n] = v[i];
            }

            // Copy elements of temp back to v
            for (i = 0; i < n; i++) {
                v[i] = temp[i];
            }
        }
        else {
            printf("\nwrong direction; should be -1 or 1!!");
            return;
        }
        while (a<n) {
            printf("%d", v[a]);
            a++;
        }

}