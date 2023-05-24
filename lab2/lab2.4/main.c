#include <stdio.h>
#define MAX 100
#include <ctype.h>

int encoding(FILE *fin, FILE *fout);
int decoding(FILE *fin, FILE *fout);

int main() {
    FILE *fin, *fout;
    char x;
    printf("FOR ENCODING PRESS E\nFOR DECODING PRESS D\n");
    scanf("%c", &x);
    switch (x) {
        case 'E':
            fin = fopen("../input.txt", "r");
            fout = fopen("../encoded.txt", "w");

            return encoding(fin,fout);
        case 'D':
            fin = fopen("../encoded.txt", "r");
            fout = fopen("../decoded.txt", "w");

            return decoding(fin,fout);
        default:
            printf("wrong decision try again");
    }
}

int encoding(FILE *fin, FILE *fout) {
    int i, h, k=0, count=0;
    char s[MAX];

    while (!feof(fin)) {
        fgets(s, MAX, fin);
        i=0; h=0;
        while (s[i] != '\0') {
            if (isdigit(s[i])) {
                if (k == 10) {
                    k -= 10;
                }
                if ((s[i] - '0' + k) > 9) {
                    fprintf(fout, "%c", s[i] + k - 10);
                }
                else {
                    fprintf(fout, "%c", s[i] + k);
                }
                k++;
            }
            else if (isalpha(s[i])) {
                if (!isalpha(s[i+1]) && s[i+1] != ' ' && s[i+1] != '\n')
                    fprintf(fout, "%c", s[i]);
                else {
                    if (isupper(s[i])) {
                        if (s[i] - 'A' + h >= 26)
                            fprintf(fout, "%c", s[i] + h - 26);
                        else
                            fprintf(fout, "%c", s[i] + h);
                        h += s[i] - 'A';
                    }
                    else {
                        if (s[i] - 'a' + h >= 26)
                            fprintf(fout, "%c", s[i] + h - 26);
                        else
                            fprintf(fout, "%c", s[i] + h);
                        h += s[i] - 'a';
                    }
                    if (h >= 26) {
                        h -= 26;
                    }
                }
            }
            else {
                if (s[i] == ' ')
                    h = 0;
                fprintf(fout, "%c", s[i]);
            }
            i++;
            count++;
        }
    }
    fclose(fin);
    fclose(fout);
    return count;
}
int decoding(FILE *fin, FILE *fout) {
    char c;
    int k=0, h, count=0;

    while(!feof(fin)) {
        c = fgetc(fin);
        if (isdigit(c)) {
            if (k == 10)
                k -= 10;
            if ((c - '0' - k) >= 0) {
                fprintf(fout, "%c", c - k);
            }
            else {
                fprintf(fout, "%c", c - k + 10);
            }
            k++;
        }
        else {
            fprintf(fout, "%c", c);
        }
        count++;
    }
    return count;
}