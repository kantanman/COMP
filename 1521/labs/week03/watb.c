// COMP1521 19t2 ... lab 03: where are the bits?
// watb.c: determine bit-field order

#include <stdio.h>
#include <stdlib.h>

struct _bit_fields {
	unsigned int a : 4;
	unsigned int b : 8;
	unsigned int c : 20;
};

int main (void)
{
    struct _bit_fields x = {4294967295, 0, 0};

    unsigned int val = sizeof(x);
    unsigned int *valPtr = &val;
    unsigned int mask = 1;

    int check[32] = {0};

    int i = 0;
    int j = 0;
    
    while (i < 32) {
    // itterates through bytes
        while (j < 32) {
        // itterates through check[]
            if ((*valPtr & mask) > 0) {
            // bit at i = 1; 
                check[j] = 1;
           
            } else {
            // bit at i = 0;
                check[j] = 0;
            }     
        i++;
        j++;        
        }
        mask = mask << 1;   
    }

    if (check[0] = 0) {
        printf("bit field is in order of c, b, a");
    } else
        printf("bit field is in order of a, b, c");

    printf("\n");
    return EXIT_SUCCESS;
}
