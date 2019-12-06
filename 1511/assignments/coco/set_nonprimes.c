#include <stdio.h>
#include <stdlib.h>


// THIS FUNCTION WILL INITIALISE nonprimes WITH THE  NON PRIMES IN YOUR HAND
void set_nonprimes(int hand[10], int nonprimes[10],  int n)  {
    int num_nonprimes=0;
    for (int i = 0; i < n; i++)  {
        int counter = 0;
        for (int factor_counter = 2; factor_counter < hand[i]; factor_counter++)  {
            if (hand[i] % factor_counter == 0)  {
                counter = 1;
                break;
            }   
        }   
        if (counter == 1)  {
            nonprimes[num_nonprimes]=hand[i];
            num_nonprimes++;
        }   
    }   
}


// TEST PRIME_CHECKER
void main()  {
    printf("This program will return the non prime cards in a hand\n\n");
    int n;
    int hand[10]={0};
    int nonprimes[10]={0};
    while (1)  {
        printf("Enter number of Elements less than 10 ctrl-c to quit\n");
        scanf("%d",&n);
        printf("Enter %d integer elements\n", n);
        for( int i = 0; i < n; i++ )  {
            scanf("%d", &hand[i]);
        }
        set_nonprimes(hand, nonprimes, n);
        printf("The non primes in the hand are\n");
        for (int i = 0; i < n; i++ )  {
            printf("%d ", nonprimes[i]);
        }
    printf("\n\n");    
    }  // end while loop

}
