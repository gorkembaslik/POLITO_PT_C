#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_CHAR 6
#define MAX_LINE 201
#define MAX_WORD 26
#define MAX_SEQ 21

int main() {
    FILE *file;
    char seq[MAX_SEQ][MAX_CHAR], text[MAX_LINE], word[MAX_WORD];
    int num_seq;
    file = fopen("../sequences.txt", "r");
    if (file == NULL) {
        printf("error opening file\n");
        return 1;
    }
    fscanf(file, "%d", &num_seq);
    for (int i=0;i<num_seq;i++){
        fscanf(file, "%s", seq[i]);
    }
    fclose(file);
    file = fopen("../text.txt", "r");
    if (file == NULL) {
        printf("error opening file\n");
        return 2;
    }
    for (int i=0;i<num_seq;i++) {
        int count=0;
        printf("Sequence %s contained in: \n", seq[i]);
        while(!feof(file)) {
            fscanf(file, "%s", word);
            count++;
            int flag=0;
            for (int x=0;x<strlen(seq[i]); x++) {
                for (int j=0; j< strlen(word); j++) {
                    if (word[j]== '\'')
                        count++;
                    while (tolower(seq[i][x]) == tolower(word[j])) {
                        x++;
                        j++;
                        flag++;
                    }
                    if (flag==strlen(seq[i])) {
                        printf("%s (position %d)\n", word, count);
                        break;
                    }
                    else {
                        x=0;
                        flag=0;
                    }
                }
                if (flag==strlen(seq[i]))
                    break;
                if (x==0)
                    break;
            }
        }
        rewind(file);
    }

    return 0;
}
