// COMP1521 19T2 ... lab 1
// cat4: Copy input to output

#include <stdio.h>
#include <stdlib.h>

static void copy (FILE *, FILE *);

int main (int argc, char *argv[])
{
    // printf("%d\n", argc); 
    if (argc == 1)
         copy (stdin, stdout);
                
    else
        for (int i = 0; i < argc - 1; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp) {
            copy(fp, stdout);
        }
        else {
            printf("Can't read name-of-file.");
        }
        fclose(fp);
        }
}

// Copy contents of input to output, char-by-char
// Assumes both files open in appropriate mode
static void copy (FILE *input, FILE *output)
{

    char buffer[10000];
    while (fgets(buffer, 10000, input) != NULL) {
        fputs(buffer, output);
    }

}





