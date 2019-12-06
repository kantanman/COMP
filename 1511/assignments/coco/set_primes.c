#include <stdio.h>
#include <stdlib.h>


// THIS FUNCTION INITIALISES pimes WITH ALL PRIME NUMBERS IN YOUR HAND
void set_primes(int hand[10], int primes[10], int n)  {
    int num_primes=0;
    for (int i = 0; i < n; i++)  {
        int counter = 0;
        for (int factor_counter = 2; factor_counter < hand[i]; factor_counter++)  {
            if (hand[i] % factor_counter == 0)  {
                counter = 1;
                break;
            }   
        }   
        if (counter == 0)  {
            primes[num_primes]=hand[i];
            num_primes++;
        }   
    }   
}


// TEST PRIME_CHECKER
void main()  {
    int n;
    int hand[10]={0};
    int primes[10]={0};
    while (1)  {
        printf("Enter number of Elements less than 10 ctrl-c to quit\n");
        scanf("%d",&n);
        printf("Enter %d integer elements\n", n);
        for( int i = 0; i < n; i++ )  {
            scanf("%d", &hand[i]);
        }
        set_primes(hand, primes, n);
        printf("The primes in the list are\n");
        for (int i = 0; i < n; i++ )  {
            printf("%d ", primes[i]);
        }
    printf("\n\n");    
    }  // end while loop

}
