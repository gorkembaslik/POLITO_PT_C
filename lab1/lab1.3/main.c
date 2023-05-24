/* Using the IDE create a new project and create a text file by the name of “Bronte.txt” inside
the project folder. The content of the file may be the following:
Ho sognato nella mia vita,
sogni che son rimasti sempre con me,
e che hanno cambiato le mie idee;
son passati attraverso il tempo e attraverso di me,
come il vino attraverso l'acqua,
ed hanno alterato il colore della mia mente.
Write/build the following program in C language. Check that there are no errors when you run
the program.

What happens when the counter is odd? What happens when the counter is even? Which is the
difference between fgets and fscanf? */

#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;

    if ((fp_read = fopen("../Bronte.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write_odd = fopen("../Output_odd.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }
    if ((fp_write_even = fopen("../Output_even", "w")) == NULL) {
        printf("Error opening file\n");
        return 3;
    }

    printf("What's your name?");
    gets(name);

    while (!feof(fp_read)) {
        counter++;
        if (counter%2==0) {
            fscanf(fp_read, "%s", file_string);
            if (!feof(fp_read)) {
                printf("%s\nI am reading: \n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s\n", file_string);
            }
        }
        else {
            fgets(file_string, 100, fp_read);
            if (!feof(fp_read)) {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write_odd);
    fclose(fp_write_even);

    return 0;
}
