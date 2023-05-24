#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d", &a, &b);
    if (a <= 0 || b<=0) {
        printf("numbers should be positive. type again");
        return 1;
    }
    if (a==b)
        printf("Result: GCF = %d", a);
    else if (a<b) {
        c = b%a;
        while (c != 0) {
            b = a;
            a = c;
            c = b%a;
        }
        printf("Result: GCF = %d", a);
    }
    else {
        c = a % b;
        while (c != 0) {
            a = b;
            b = c;
            c = a % b;
        }
        printf("Result: GCF = %d", b);
    }
}