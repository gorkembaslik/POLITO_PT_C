#include <stdio.h>
int main(){
    FILE *fpin, *fpout;
    char a;
    float op1, op2;

    if ((fpin = fopen("../Operations.txt", "r")) == NULL) {
        printf("ERORRR FILE DOES NOT EXIST\n");
        return 1;
    }
    if ((fpout = fopen("../Results.txt", "w")) == NULL) {
        printf("ERORRR FILE\n");
        return 2;
    }
    while (!feof(fpin)) {
        fscanf(fpin, "%c%f%f\n", &a, &op1, &op2);
        if (!feof(fpin)) {
            if (a == '+')
                op1 += op2;
            else if (a == '-')
                op1 -= op2;
            else if (a == '/')
                if (op2 == 0) {
                    printf("Impossible operation");
                    return 3;
                }
                else
                    op1 /= op2;
            else if (a == '*')
                op1 *= op2;
            else {
                printf("You can choose one of these operations >> + - * /");
                return 4;
            }
        }
        fprintf(fpout,"%c %.2f\n", a, op1);
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}