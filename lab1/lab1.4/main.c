#include <stdio.h>
#define PI 3.14

int main() {
    char type, a;
    int x;
    double area;
    printf("For area of a square type S, for circle type C: ");
    scanf("%c", &type);
    if (type == 'S') {
        printf("diagonal(D) or side(S) value of square?its value? (write adjacent): ");
        scanf(" %c %d", &a, &x);
        if (a == 'D') {
            area = (float) (x * x) / 2.0;
            printf("area of the square is: %.3f", area);
        } else if (a == 'S') {
            area = (float) (x * x);
            printf("area of the square is: %.3f", area);
        } else {
            printf("wrong word check again");
            return 2;
        }
    } else if (type == 'C') {
        printf("diameter(D) or radius(R) value of square? and its value (write adjacent): ");
        scanf(" %c %d", &a, &x);
        if (a == 'D') {
            area = ((float) (x) / 2.0) * ((float) (x) / 2.0) * PI;
            printf("area of the circle is: %.3f", area);
        }
        if (a == 'R') {
            area = (float) (x * x) * PI;
            printf("area of the circle is: %.3f", area);
        } else
            printf("\nwrong word check again");
        return 3;
    } else {
        printf("check what you wrote!!");
        return 1;
    }
    return 0;
}
    /*
     #include <stdio.h>
#define PI 3.14

int main(){
    char a, b;
    int x;
    float area;
    printf("Which Geometric Shape do you wanna calculate the area of? Square (S) or Circle (C) ? \n");
    printf("Diameter (D) or Radius (R) or Side (S) length you wanna use? \n");
    printf("how much the length is? ");
    scanf("%c %c%d",&a,&b, &x); // FORMAT KISMINDA %c LERIN ARASINA KOYDUĞUMUZ BOŞLUK BİZE BOŞLUKLARI KARAKTER OLARAK SAYMAMA RAHATLIĞINI TANIYOR.
    //EĞER ONLAR BITISIK OLSAYDI B DEĞERİ SPACE KARAKTERINI OKUYOR.
    switch (a) {
        case 'S':
            if (b == 'D') {
                area = x*x/2.0;
                printf("The area of the square with diagonal %d is %.2f", x, area);
            }
            else if (b == 'S') {
                area = (float)x*x;
                printf("The area of the square with side %d is %.2f", x, area);
            } else
                return 1;
           break;
        case 'C':
            if (b == 'D') {
                area = PI*(x/2.0)*(x/2.0);
                printf("The area of the circle with diagonal %d is %.2f", x, area);
            }
            else if (b == 'R') {
                area = PI*x*x;
                printf("The area of the circle with radius %d is %.2f", x, area);
            }
            else
                return 2;
            break;
        default:
            printf("Wrong answer try again\n");
            return 3;
    }
    return 0;
}
     */