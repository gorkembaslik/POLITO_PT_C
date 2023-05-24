#include <stdio.h>
#define MAX 100

int compressing(FILE *fpin, FILE *fpout);
int decompressing(FILE *fpin, FILE *fpout);

int main() {
    FILE *fpin, *fpout;
    char x;
    printf("FOR COMPRESSING PRESS C\nFOR DECOMPRESSING PRESS D\n");
    scanf("%c", &x);
    switch (x) {
        case 'C':
            fpin = fopen("../source.txt", "r");
            fpout = fopen("../compressed.txt", "w");

            return compressing(fpin,fpout);
        case 'D':
            fpin = fopen("../compressed.txt", "r");
            fpout = fopen("../source2.txt", "w");

            return decompressing(fpin,fpout);
        default:
            printf("wrong decision try again");
    }
}

int compressing(FILE *fpin, FILE *fpout) {
    int a=0,i,count;
    char s[MAX];

    while(!feof(fpin)){
        fgets(s, MAX, fpin);
        i=0;
        while (s[i] != '\0') {
            count =0;
            while (s[i] == s[i+1] && s[i+1] != '\0') {
                count +=1;
                i++;
            }
            if (2 <= count && count < 10) {
                fprintf(fpout, "%c$%d", s[i], count);
            } else if (count == 10) {
                fprintf(fpout, "%c$9%c", s[i], s[i]);
            } else if (count == 11) {
                fprintf(fpout, "%c$9%c%c", s[i], s[i], s[i]);
            } else if (count >= 12) {
                fprintf(fpout,"%c$9%c$%d", s[i], s[i], count - 10);
            } else if (count == 1) {
                fprintf(fpout,"%c%c", s[i], s[i]);
            } else
                fprintf(fpout,"%c", s[i]);
            i++;
        }
        a += i;
    }
    fclose(fpin);
    fclose(fpout);
    return a;
}
int decompressing(FILE *fpin, FILE *fpout) {
    int a=0,i,j,count;
    char s[MAX];

    fpin = fopen("../compressed.txt", "r");
    fpout = fopen("../source2.txt", "w");

    while(!feof(fpin)){
        fgets(s, MAX, fpin);
        i=0;
        while (s[i] != '\0') {
            if (s[i] == '$') {
                count = s[i+1] - '0';
                for (j=0;j<count; j++) {
                    fprintf(fpout, "%c", s[i-1]);
                }
                i++;
            }
            else {
                fprintf(fpout, "%c", s[i]);
            }
            i++;
        }
        a +=i;
    }
    fclose(fpin);
    fclose(fpout);
    return a;
}