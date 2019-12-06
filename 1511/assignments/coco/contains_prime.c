#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// THIS FUNCTION, GIVEN AN ARRAY OF INTEGERS BETWEEEN 10..49
// WILL RETRUN true IF THE ARRAY CONTAINS A PRIME
bool contains_prime(int hand[], int n) {
    int primes[11] = {11,13,17,19,23,29,31,37,41,43,47};
    for( int i = 0; i < 11; i++ )  {
        for ( int j = 0; j < n; j++ )  {
             if ( hand[j] == primes[i] )   
                 { return true; }
        }  // end j loop
    }   // end i loop
    return false;  
}

// Main tests the is_containing_prime function
void main()  {
    int arr[10];
    int n;

    while (1)  {  // infinite loop, will need to crtl c to terminate program
        printf("Enter number of elements  crtl-c to exit\n");
        scanf("%d",&n);
        printf(" Enter %d integers between 10 and 49\n", n); 
        // easier to scanf in a for loop
        for( int i = 0; i < n; i++ ) { 
            scanf("%d", &arr[i] );
        }   
        if ( contains_prime(arr, n) == true)  {
             printf("The list contains a prime\n");
        } else   {   
             printf("The list does not contain a prime\n");
        } 
     }   // end while loop
}




