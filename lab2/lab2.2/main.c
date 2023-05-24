#include <stdio.h>

int main() {
    int x0=0, x1=1, x2, n;

    printf("how many numbers of fibonacci series?: ");
    scanf("%d", &n);
    printf("The fibonacci serie is: %d %d", x0, x1);

    for (int i=2; i<n; i++) {
        x2= x0 + x1;
        printf(" %d", x2);
        x0 = x1;
        x1 = x2;
    }
}