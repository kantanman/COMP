// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by EUGENE CLARK (z5258551)
// on 1 APRIL 2019
//
// Submitted on 7 APRIL 2019

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49

//Function declerations 

int min(int a, int b);

bool is_prime(int n); 
bool is_cocomposite( int a, int b);
bool contains_prime(int hand[], int n);
bool contains_nonprime(int hand[],int n);


void set_primes(int hand[N_CARDS_INITIAL_HAND], int primes[N_CARDS_INITIAL_HAND], int n);
void set_nonprimes(int hand[N_CARDS_INITIAL_HAND], int nonprimes[N_CARDS_INITIAL_HAND],  int n);
void set_cocomposite(int hand[N_CARDS_INITIAL_HAND], int cocomposite[N_CARDS_INITIAL_HAND], int n, int first_card);

int  number_of_elements( int array[], int n);

void read_cards(int array[], int n);
void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);

int duck_highest( int legal_plays[N_CARDS_INITIAL_HAND], int n, int this_round[N_PLAYERS], int m);
int play_highest( int legal_plays[N_CARDS_INITIAL_HAND], int num_elements, int max);
int play_lowest( int legal_plays[N_CARDS_INITIAL_HAND], int num_elements);
int play_strategy(int legal_plays[N_CARDS_INITIAL_HAND], int previous_rounds[N_CARDS], int my_hand[N_CARDS_INITIAL_HAND], int this_round[N_PLAYERS], int round, int state );


int main(void) {
    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}


// THIS FUNCTION RETURN THE MINIMUM OF TWO INTEGERS
// USAGE:
// int a=3, b=5;
// min( a , b )  will return 3

int min(int a, int b) {
   if ( a <  b )
      return a;
   return b;
}


// THIS FUNCTION RETURN TRUE IF n is a prime
// USAGE:
// eg 1.
// int a = 17
// is_prime( a )  will return true because 17 is a prime
// eg 2
// int a = 25
// is_prime(a) will return false because 25 is not a prime

bool is_prime( int n ) {
    if (n <= 1) return false;
    if (n % 2 == 0 && n > 2) return false;
    for(int i = 3; i < n / 2; i+= 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// THIS FUNCTION WILL RETURN TRUE IF TWO INTEGERS ARE COCOMPOSITE
// USAGE :
// eg 1.
// int a = 18, int b = 25;
// is_cocomposite( a, b )  will return true because 18 and 36 have a common factor, 2
// eg 2.
// int a = 16, b= 21;
// is_cocomposite( a, b ) will return false because 16 and 21 have no common factors.

bool is_cocomposite(int a, int b) {
   int smallest = min(a, b);
   for( int i = 2; i < smallest; i++) {
      if ( (a % i == 0) && (b % i == 0) )
         return true;
   }
   return false;        
}


// THIS FUNCTION RETURNs TRUE IF YOUR HAND CONTAINS A PRIME
// FALSE OTHERWISE
// USAGE:
// eg 1. 
// int hand[] = {11, 14, 16 18)
// Contains_prime will return true since 11 is prime 
// eg 2. 
// int hand[] = {33, 35, 36, 38)
// contains_prime will return false since there are no primes in this hand

bool contains_prime( int hand[], int n ) {
    for ( int i = 0; i < n; i++ )  {
        if ( is_prime(hand[i]) == true )
            return true;
    }   
    return false;
}


// THIS FUNCTION WILL RETURN TRUE IF YOUR HAND CONTAINS A NON PRIME
// FALSE OTHERWISE
// USAGE:
// eg 1
// int hand[] = {11, 13, 17, 20}
// contains_nonprime will return true since 20 is non-prime 
bool contains_nonprime( int hand[], int n ) {
    for ( int i = 0; i < n; i++ )  {
        if ( is_prime(hand[i]) == false )
            return true;
    }   
    return false;
}


// THIS FUNCTION INITIALISES primes WITH ALL PRIME NUMBERS IN YOUR HAND
// USAGE:
// int hand[10] = {11, 12, 14, 17, 20, 24, 26, 30, 33, 37}
// set_primes will make primes[10] = {11, 17, 37, 0, 0, 0, 0, 0, 0, 0} 
void set_primes( int hand[N_CARDS_INITIAL_HAND], int primes[N_CARDS_INITIAL_HAND], int n ) {
    int counter=0;
    for (int i = 0; i < n; i++)  {
        if( is_prime(hand[i]) == true ) {
            primes[counter]=hand[i];
            counter++;
        }
    }
} 


// THIS FUNCTION WILL INITIALISE nonprimes WITH THE  NON PRIMES IN YOUR HAND
// USAGE:
// int hand[10] = {11, 12, 14, 17, 20, 24, 26, 30, 33, 37}
// Set_nonprimes will make nonprimes[10] = {12, 14, 20, 24, 26, 30, 33, 0, 0, 0}
void set_nonprimes(int hand[N_CARDS_INITIAL_HAND], int nonprimes[N_CARDS_INITIAL_HAND],  int n) {
    int counter=0;
    for (int i = 0; i < n; i++)  {
        if( is_prime(hand[i]) == false ) {
            nonprimes[counter]=hand[i];
            counter++;
        }
    }
}

// THIS FUNCTION WILL INITIALISE composite IF is_composite IS RETURNED true
// USAGE:
// int hand[10] = {11, 12, 14, 17, 20, 24, 26, 30, 33, 37}
// set_composite will make cocomposite[10] = {
void set_cocomposite(int hand[N_CARDS_INITIAL_HAND], int cocomposite[N_CARDS_INITIAL_HAND], int n, int first_card) {
    int counter=0;
    for (int i = 0; i < n; i++) {
        if( is_cocomposite(hand[i],first_card) == true) {
            cocomposite[counter]=hand[i];
            counter++;
        }
    }
}


// THIS FUNCTION RETURN THE NUMBER OF ELEMENTS IN AN ARRAY
// UP UNTIL A ZERO
// USAGE :
// int my_hand[10] = { 10, 12, 13, 14 ,0,0,0,0,0,0 }
// number_of_elements( my_hand )  returns 4

int number_of_elements( int array[], int n) {
  for ( int i = 0; i < n; i++) 
      if ( array[i] == 0 )
          return i;
  return n;
}
  

void read_cards(int array[], int n) {
    //  READS n CARDS INTO AN ARRAY AND CHECKS THAT CARDS ARE IN CORRECT RANGE
    for ( int i = 0; i < n; i++ ) {
        assert(scanf("%d",&array[i]) == 1);
        assert(array[i] >= CARD_MIN && array[i] <= CARD_MAX);
    }
}


void print_player_name(void) {
    // PRINTS MY NAME
    printf("I'm EuGEnE\n");
}


void choose_discards() {
    int my_hand[N_CARDS_INITIAL_HAND];
    read_cards(my_hand, N_CARDS_INITIAL_HAND);
    int discard[3]={0};
    int discard_pref[40] = {49, 42, 47, 43, 45, 41, 39, 37, 31, 29, 48, 46, 44, 25,
                            27, 35, 40, 38, 36, 34, 33, 32, 30, 28, 26, 24, 23, 
                            22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10};
    int counter = 0;
    for(int j = 0; j < 40; j++)
    {
        for ( int i = 0;  i < N_CARDS_INITIAL_HAND; i++ )
        {
            if ( my_hand[N_CARDS_INITIAL_HAND-i-1] == discard_pref[j] )
            {
                discard[counter] = discard_pref[j];
                counter++;
                break;
            }
        }       
        if (counter == 3)
        break;
    }
   
    printf("%d %d %d\n", discard[0], discard[1], discard[2]); 
}

void choose_card_to_play(void) {
    int n_cards_in_hand;
    int n_cards_played_this_round;
    int table_position;

    //ARRAY DECLARATIONS
    int my_hand[N_CARDS_INITIAL_HAND]={0};
    int cards_played_this_round[N_PLAYERS] = {0};
    int cards_played_in_previous_rounds[N_CARDS] = {0};
    int discards[N_CARDS_DISCARDED] = {0};
    int discards_received[N_CARDS_DISCARDED] = {0};

    int primes_in_my_hand[N_CARDS_INITIAL_HAND]={0};
    int nonprimes_in_my_hand[N_CARDS_INITIAL_HAND]={0};
    int cocomposite_to_first_card_in_my_hand[N_CARDS_INITIAL_HAND]={0};

    int legal_plays[N_CARDS_INITIAL_HAND]={0}; 
    

    // READS THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
    assert(scanf("%d %d %d", &n_cards_in_hand, &n_cards_played_this_round, &table_position) == 3);
    assert(n_cards_in_hand >= 1 && n_cards_in_hand <= N_CARDS_INITIAL_HAND);
    assert(n_cards_played_this_round >= 0 && n_cards_played_this_round < N_PLAYERS);
    assert(table_position >= 0 && table_position < N_PLAYERS); 

    // READS THE CARDS OF MY HAND INTO AN ARRAY
    read_cards(my_hand, n_cards_in_hand);
    // READS THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    read_cards(cards_played_this_round, n_cards_played_this_round);
    // READS THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    read_cards(cards_played_in_previous_rounds, N_PLAYERS * ( N_CARDS_INITIAL_HAND - n_cards_in_hand )); 
    //READ DISCARDS
    read_cards(discards, N_CARDS_DISCARDED);
    read_cards(discards_received, N_CARDS_DISCARDED);
   
    //INITIALISE primes_in_my_hand, non_primes_in_my_hand, coprime_to_firstcard
  
    set_primes(my_hand, primes_in_my_hand, n_cards_in_hand);
    set_nonprimes(my_hand, nonprimes_in_my_hand, n_cards_in_hand);
    set_cocomposite(my_hand, cocomposite_to_first_card_in_my_hand, n_cards_in_hand, cards_played_this_round[0]);   

    //check if your playing first card in a round
    if ( n_cards_played_this_round == 0) {
       //check is a prime numbered card has been played yet
        if ( contains_prime(cards_played_in_previous_rounds , N_CARDS) == true ) {   
            //play any card
            for( int i = 0; i < N_CARDS_INITIAL_HAND; i++)
               legal_plays[i] = my_hand[i]; 
            int state = 1;
            int played = play_strategy( legal_plays, cards_played_in_previous_rounds, my_hand,
                                        cards_played_this_round, n_cards_in_hand,  state);            
            printf("%d\n",played);
        }  
        if ( contains_prime(cards_played_in_previous_rounds , N_CARDS) == false ) {
            if ( contains_nonprime(my_hand, n_cards_in_hand) == true ) {
                // play non prime card
                for( int i = 0; i < N_CARDS_INITIAL_HAND; i++)
                   legal_plays[i] = nonprimes_in_my_hand[i];
                int state = 2;
                int played =  play_strategy( legal_plays, cards_played_in_previous_rounds, my_hand, 
                                                cards_played_this_round, n_cards_in_hand,  state);
               
                printf("%d\n",played);
            }   
            if ( contains_nonprime(my_hand, n_cards_in_hand) == false ) {
                 // play any card 
                for( int i = 0; i < N_CARDS_INITIAL_HAND; i++)
                    legal_plays[i] = my_hand[i];
                int state = 3;
                int played = play_strategy( legal_plays, cards_played_in_previous_rounds, my_hand,
                cards_played_this_round, n_cards_in_hand,  state);
                printf("%d\n",played);
            }
        }
    }


    if ( n_cards_played_this_round != 0) {
        if ( is_prime(cards_played_this_round[0]) == true ) {
            if ( contains_prime(my_hand, n_cards_in_hand) == true ) {
                //play prime card
                for( int i = 0; i < N_CARDS_INITIAL_HAND; i++ )
                    legal_plays[i] = primes_in_my_hand[i];
                int state = 4;
                int played =  play_strategy( legal_plays, cards_played_in_previous_rounds, my_hand, 
                                             cards_played_this_round, n_cards_in_hand,  state);
                printf("%d\n",played);
            }           
            if ( contains_prime(my_hand, n_cards_in_hand) == false ) {
                //play any card
                for( int i = 0; i < N_CARDS_INITIAL_HAND; i++)
                   legal_plays[i] = my_hand[i];
                int state = 5;
                int played = play_strategy( legal_plays, cards_played_in_previous_rounds, my_hand, 
                                            cards_played_this_round, n_cards_in_hand,  state);
                printf("%d\n",played);
            }
        } 
        if ( is_prime(cards_played_this_round[0]) == false ) {
            if ( cocomposite_to_first_card_in_my_hand[0] != 0) {
                //play  composite card in your hand
                for( int i = 0; i < N_CARDS_INITIAL_HAND; i++)
                    legal_plays[i] = cocomposite_to_first_card_in_my_hand[i];
                int state = 6;
                int played = play_strategy( legal_plays, cards_played_in_previous_rounds, my_hand, 
                                            cards_played_this_round, n_cards_in_hand,  state);
                printf("%d\n", played); 
            }
            if ( cocomposite_to_first_card_in_my_hand[0] == 0) {
                //play any card
                for( int i = 0; i < N_CARDS_INITIAL_HAND; i++)
                   legal_plays[i] = my_hand[i];
                int state = 7;
                int played = play_strategy( legal_plays, cards_played_in_previous_rounds, my_hand, 
                                            cards_played_this_round, n_cards_in_hand,  state);         
                printf("%d\n", played);
            }
        }
    } 
}


  
int play_highest( int legal_plays[N_CARDS_INITIAL_HAND], int num_elements, int max) {
   int card = legal_plays[num_elements-1];
   // search for highest card less than max, if it exists
   for( int i = 0; i < num_elements; i++ ) {
      card = legal_plays[num_elements-1-i];
      if ( card < max )
         return card;
   }
   // if a card cant be found that is less than max, then highest card is played
   return card;
}



int play_lowest( int legal_plays[N_CARDS_INITIAL_HAND], int num_elements) {
    return legal_plays[0];
}


//  PLAY HIGHEST CARD TO LOSE ROUND IF POSSIBLE
int duck_highest( int legal_plays[N_CARDS_INITIAL_HAND], int n, int this_round[4], int m) {  
   int highest = this_round[0];
   // for loop will find highest co-composite card to first card. 
   // if first card is a prime it need to be dealt with seperately
   for( int i = 0; i < m; i++) {
      if ( highest < this_round[i] && is_cocomposite(this_round[0],this_round[i]))
         highest = this_round[i];
   }
   // check if first card is prime and find highest prime in the round
   if ( is_prime(this_round[0]) ) {
      for ( int i = 0; i < m; i++ ) {
         if ( highest < this_round[i] && is_prime(this_round[i]) )
            highest = this_round[i];
      }
   }
   // play lower card to first card if you can
   for ( int i = 0; i < n; i++ ) {
      if ( legal_plays[n-i-1] < highest )
          return legal_plays[n-i-1];
   }
   // play highest card since you will loose the round anyway
   return legal_plays[n-1];
}



int  play_strategy(int legal_plays[N_CARDS_INITIAL_HAND], int previous_rounds[N_CARDS], int my_hand[N_CARDS_INITIAL_HAND], int this_round[N_PLAYERS], int round, int state ) { 
// SIMPLE STRATEGY TO DISCARD HIGH CARDS FOR THE FIRST 5 ROUNDS, AND DUCK THE LAST 5 ROUNDS. 
// IF A PRIME IS PLAYED FIRST OR A 42 THE PROGRAM WILL ALWAYS DUCK
// first hand is 10th round

    assert( state > 0 && state < 8);
    int n = number_of_elements( legal_plays, 10 );
    int m = number_of_elements( this_round, 4 );
    int card;
    int has_douglas = 0;
    int douglas_played = 0;  

    for (int i = 0; i < 40; i++) {
        if ( previous_rounds[i] == 42 )
            douglas_played = 1;
    }

    for (int i = 0; i < 10; i++)
    {
        if ( my_hand[i] == 42 )
             has_douglas = 1;
    }
    // if the douglas has been played in this round, then duck the highest card    
    if( this_round[0]==42 || this_round[1]==42 || this_round[2]==42 || this_round[3]==42 )
    {
        card = duck_highest( legal_plays, n, this_round, m);   
        return card;
    }
    // if you have the douglas, and you are not playing first, play it when someone plays higher
    // than 42
    if(has_douglas == 1 && m > 0)
    {
        for (int i = 0; i < m; i++)
        {
            int a = this_round[i];
            if( a == 44 || a == 45 || a == 46 || a == 48 || a == 49)
            {
                if( contains_prime(this_round, 1) == false)
                { 
                    return 42;    	
                }
            }   	     
        } 
        // if you cant play 42, play highest card that is not 42
        if (round > 5)
        {
            card = play_highest(legal_plays, n, 50);
           // hack to make chance of playing high prime card unlikely
            if ( is_prime(card) )
               card = play_highest(legal_plays, n, card);
            if ( card == 42 && n > 1 )
            {
                card = play_highest( legal_plays, n , 42);
                if ( is_prime(card) )
                    card = play_highest(legal_plays, n, card);
                return card;
            }
            if ( is_prime(card) )
                card = play_highest(legal_plays, n, card);
            return card; 
        }         
    }
    // if you have the douglas and you are first player, play  a high card that is not prime 
    if(has_douglas == 1 && m == 0 && round > 5)
    {          
        card = play_highest(legal_plays, n, 49); 
        if ( is_prime(card) )
            card = play_highest(legal_plays, n, card);  
        if ( (card == 42 || card == 43 || card == 47 )  && (n > 1) )
        {   
            card = play_highest( legal_plays, n , 42); 
            if ( is_prime(card) )
               card = play_highest(legal_plays, n, card);           
            return card;
        }
        if ( is_prime(card) )
            card = play_highest(legal_plays, n, card);
        return card;
    }
     
        
    if( contains_prime(this_round, 4) == false && m == 3)
    {
        if( this_round[0] != 42 || this_round[1] != 42 || this_round[2] != 42)
        {
            card = play_highest( legal_plays, n, 50);
            return card;
        }
    }


    if( state == 4)
    {  
        card = duck_highest( legal_plays, n, this_round, m);
        return card;	
    }

    if( douglas_played == 0 && round > 5)
    {
        card = play_highest( legal_plays, n, 42);
        if ( is_prime(card) )
            card = play_highest(legal_plays, n, card);
        return card;
    }


    if ( round > 5 )           // play highest cards for first five rounds
    {
        card = play_highest( legal_plays, n, 50);
        if ( card == 42 && n > 1 ) 
        {
            card = play_highest( legal_plays, n, 42);  
            return card;
        } 
        if ( is_prime(this_round[0]) == true )
        {
            card = duck_highest( legal_plays, n, this_round, m);
            return card;
        }
             
        return card;
    }

    else
        card = duck_highest( legal_plays, n, this_round, m);
    
     // FOR THE LAST 5 ROUNDS

    // state 1 
    // playing first card in round 
    // prime has been played
    // legal_plays contain the whole hand


    if (state == 1)
    {   
        card = play_lowest( legal_plays, n); 
        return card;
    }

    // state 2
    // playing first card in round 
    // prime has not been played
    // hand  contains non prime cards
    // legal_plays contain whole hand with prime card removed
    if (state == 2)  
    {  
        card = play_lowest( legal_plays, n);
        return card;
    }

    // state 3
    // playing first card in round 
    // prime has not been played
    // hand does not contain non prime card
    // legal_plays contains whole hand
    if (state == 3)  
    {   
        card = play_lowest( legal_plays, n); 
        return card;
    }

    // state 4
    // playing non first card in round 
    // first card was a prime
    // hand does contais prime card
    // legal_plays contains only prime cards
    if (state == 4)  
    { 
        card = duck_highest( legal_plays, n, this_round, m );  
        return card;
    }
    
    // state 5
    // playing non first card in round 
    // first card was a prime
    // hand does not contais prime card
    // legal_plays contains whole hand
    if (state == 5)  
    {   
        card = play_highest( legal_plays, n, 50);
        return card;
    }
    // state 6
    // playing non first card in round 
    // first card was not a prime
    // hand does contain cocomposite card
    // legal_plays contains all cocomposite cards to first card played
    if (state == 6)  
    {   
        card = duck_highest( legal_plays, n, this_round, m );
        return card;
    }

    // state 7
    // playing non first card in round 
    // first card was not a prime
    // hand does contais no cocomposite card
    // legal_plays contains all primes
    if (state == 7)  
    {   
        card = play_highest( legal_plays, n, 50);   
        return card;
    }         

    return legal_plays[0];
}
