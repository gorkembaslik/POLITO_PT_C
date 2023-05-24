#include <stdio.h>
#include <string.h>
#define MAX 9
// bad code

int main() {
    char binary[MAX];
    int i, j, b,k, x;
    printf("binary text: ");
    do {
        scanf("%s", binary);
        b = 0;
        for (i = MAX - 2, j = 0; i > 0 && j < MAX - 1; i--, j++) {
            k = 0;
            if (binary[i]=='0')
                continue;
            else if (binary[i] == '1') {
                x=1;
                while (k < j) {
                    x *= 2;
                    k++;
                }
                b+=x;
            } else {
                printf("error: there is a not binary number!!\n");
                return 1;
            }
        }
        printf("%c", b);
    } while (strcmp(binary, "end") != 0);
    return 0;
}
