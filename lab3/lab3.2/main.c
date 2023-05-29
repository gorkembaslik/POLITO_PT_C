#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int main() {
    FILE *fin;
    char line[MAX];
    int i, j, no=1, check;

    if ((fin = fopen("../expr.txt", "r")) == NULL) {
        printf("problem on reading file\n");
        return 1;
    }
    while(!feof(fin)) {
        fgets(line, MAX, fin);
        int flag=0, error= 0;
        for(i=0; i<strlen(line)-1; i++) {
            while (line[i] == ' ') {
                i++;
            }
            j = i + 1;
            if (line[i] == '(') {
                while (line[j] == ' ') {
                    j++;
                }
                if (line[j] != '(' && !isdigit(line[j])) {
                    error=1;
                }
                flag +=1;
            }
            else if (isdigit(line[i]) || line[i] == ')') {
                check = j;
                while (line[j] == ' ') {
                    j++;
                }
                if (line[j] == ')')
                    flag +=1;
                else if (isdigit(line[i])) {
                    if (isdigit(line[j]) && check != j)
                        error=1;
                }
                else if (line[j] != '+' && line[j] != '-' && line[j] != '*' && line[j] != '/' && line[j] != '%' && line[j] != '\n') {
                    error =1;
                }
            }
            else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%') {
                while (line[j]== ' ') {
                    j++;
                }
                if (line[j] != '(' && !isdigit(line[j])) {
                    error=1;
                }
            }
            if (error) {
                printf("Error in expression %d\n", no);
                break;
            }
        }
        if (error==0 && flag%2!=0) {
            printf("Error in expression %d\n", no);
        }
        no++;
    }
    fclose(fin);
    return 0;
}
