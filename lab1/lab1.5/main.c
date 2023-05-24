#include <stdio.h>
int main(){
    char a;
    float op1, op2;
    printf("Type the arithmetic operation you want to perform: ");
    a = getchar();
    printf("Type the values: ");
    scanf("%f%f", &op1,&op2);
    if (a == '+')
        op1 += op2;
    else if (a == '-')
            op1 -= op2;
    else if (a == '/')
        if (op2 == 0) {
            printf("Impossible operation");
            return 1;
        }
        else
            op1 /= op2;
    else if (a == '*')
        op1 *= op2;
    else {
        printf("You can choose one of these operations >> + - * /");
        return 2;
    }
    printf("%c %.2f", a, op1);
    return 0;
}