#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define FILE_INPUT "../input.txt"
#define FILE_OUTPUT "../output.txt"

#define MAX 100
int main() {
    FILE *fin, *fout;
    char s[MAX], c;
    int i, count=0, toupp=0;

    fin = fopen(FILE_INPUT, "r");
    fout = fopen(FILE_OUTPUT, "w");

    while (!feof(fin)) {
        fgets(s, MAX, fin);
        if (!feof(fin)) {
            for (i=0;i<strlen(s)-1; i++) {
                if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
                    toupp = 1;
                }
                if (isalpha(s[i])) {
                    if (toupp) {
                        s[i]= toupper(s[i]);
                        toupp = 0;
                    }
                    fprintf(fout, "%c", s[i]);
                    count++;
                }
                else if (isdigit(s[i])) {
                    fprintf(fout, "%c", '*');
                    count++;
                }
                else if (ispunct(s[i]) && (s[i+1] != ' ') && s[i+1] != '\n' && !ispunct(s[i+1])) {
                    fprintf(fout, "%c ", s[i]);
                    count += 2;
                }
                else {
                    fprintf(fout, "%c", s[i]);
                    count++;
                }

                if (count == 25) {
                    fprintf(fout, "| c:25\n");
                    count = 0;
                }
            }
            i = count;
            for (;count<25;count++) {
                fprintf(fout, " ");
            }
            fprintf(fout, "| c:%d\n", i);
            count =0;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}