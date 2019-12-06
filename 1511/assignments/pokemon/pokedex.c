// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c

// This program was written by Eugene Clark (z5258551)
// on 20th April
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call.
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;
    struct pokenode *current;
};

// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    struct pokenode *previous;
    struct pokenode *next_evo;
    int found;
    Pokemon         pokemon;
};

// Add prototypes for any extra functions you create here.
static void print_astr(char *string);
static int get_found(Pokedex pokedex);
static void insertOrdered(Pokedex pokedex, Pokemon pokemon);
int checkSubstring(char string[50], char substring[50]); 

Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    new_pokedex->head = NULL;
    new_pokedex->current = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// NOTE with add_pokemon: Check that pokemon ID is unique! 

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {

    int id = pokemon_id(pokemon); 
    struct pokenode *q = pokedex->head;

    // Checking if ID already exists
    while (q != NULL){
        if (pokemon_id(q->pokemon) == id ){
            fprintf(stderr, "There's already a Pokemon with pokemon_id %d\n!", id);
            exit(1);
        }
        q = q->next;
    }    
    struct pokenode *p ;
    p = malloc(sizeof(struct pokenode));
    if (p == NULL) {
        printf("Malloc failed, out of memory\n");
        exit(1);
    }
    // Adding new pokemon to the head of the pokedex
    p->pokemon = pokemon;
    p->next = pokedex->head;
    p->previous = NULL;
    p->next_evo = NULL;
    if (pokedex->head != NULL )
        pokedex->head->previous = p;
    pokedex->head = p;
    if (pokedex->current == NULL) {
        pokedex->current = p;    
    }
    p->found = 0; 
}

void detail_pokemon(Pokedex pokedex) {

    struct pokenode *q = pokedex->current;
    if (q != NULL) { 
        Pokemon p = pokedex->current->pokemon;
        // If pokemon is found, print all details
        if (q->found == 1) {
            printf("Id: %03d\n", pokemon_id(p));
            printf("Name: %s\n", pokemon_name(p));
            printf("Height: %.1lfm\n", pokemon_height(p) );
            printf("Weight: %.1lfkg\n", pokemon_weight(p) );
            printf("Type: %s ", pokemon_type_to_string(pokemon_first_type(p)));
            if (pokemon_second_type(p) != NONE_TYPE) 
                printf("%s", pokemon_type_to_string(pokemon_second_type(p)));
            printf("\n");
        }
        // if pokemon is not found, print hidden details
        if (q->found == 0) {
            printf("Id: %03d\n", pokemon_id(p));
            printf("Name: ");
            print_astr(pokemon_name(p));
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");      
        }
    } 
}

Pokemon get_current_pokemon(Pokedex pokedex) {   
    if (pokedex->current == NULL) {
        return NULL;
    }
    return pokedex->current->pokemon;  
}

void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->current != NULL) {
        pokedex->current->found = 1;
        
    }
}    

void print_pokemon(Pokedex pokedex) {
    struct pokenode *p = pokedex->head;
    // if pokedex is empty, print nothing
    if (p == NULL)
        return;
    // traverse to the top of the list (which is when p->next == NULL)
    while (1) { 
        if (p -> next == NULL)
           break; 
        p= p -> next;       
    }
    // Printing from the top of the list to head
    while (p != NULL) {
        if (p->found == 1) {
            if (pokedex->current == p)
                printf("--> #%03d: %s", pokemon_id(p->pokemon), pokemon_name(p->pokemon));
            else
                printf("    #%03d: %s", pokemon_id(p->pokemon), pokemon_name(p->pokemon));
        }  
        else {
            if (pokedex->current == p) {
                printf("--> #%03d: ", pokemon_id(p->pokemon));
                print_astr(pokemon_name(p->pokemon));
               
            }
            else {
                printf("    #%03d: ", pokemon_id(p->pokemon));
                print_astr(pokemon_name(p->pokemon));
            }
        }
        printf("\n");
        p = p -> previous;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    if (pokedex->current != NULL && pokedex->current->previous != NULL)
        pokedex->current = pokedex->current->previous;
}

void prev_pokemon(Pokedex pokedex) {
    if (pokedex->current != NULL && pokedex->current->next != NULL)
        pokedex->current = pokedex->current->next;
    
}

void change_current_pokemon(Pokedex pokedex, int id) {

    struct pokenode *p = pokedex->head;
    while (p != NULL) {
        if (pokemon_id(p->pokemon) == id) {
            pokedex->current = p;
            break;
        } 
        p = p->next;   
    }     
}

void remove_pokemon(Pokedex pokedex) {

    // no element in the list
    if (pokedex->current == NULL)
        return;
    struct pokenode *currNode = pokedex->current;    
    struct pokenode *nextNode = currNode->next;
    struct pokenode *prevNode = currNode->previous;
    int id = pokemon_id(pokedex->current->pokemon);

    // tranverse pokedex and set evolution to null if it points to a removed pokem id
    struct pokenode *p = pokedex->head;
    while (p != NULL) {
        if ( p->next_evo != NULL) {
            if (pokemon_id(p->next_evo->pokemon) == id)  {
                p->next_evo = NULL;
            }
        }
        p = p->next;
    }


    // List is reversed. ie, if you are are the top of the list, the next node 
    // is NULL       and if you are at the bottom of the list, prevNode is NULL 
    if (nextNode != NULL) {
        nextNode->previous = prevNode;
    }
    if (prevNode != NULL) {
        prevNode->next = nextNode;
    }
    destroy_pokemon(currNode->pokemon);
    free(currNode);
    if (prevNode == NULL) {
        pokedex->current = nextNode;
        pokedex->head = nextNode;
        return;
    } 
    pokedex->current = prevNode;
}

void destroy_pokedex(Pokedex pokedex) {

    struct pokenode *p = pokedex->head;
    struct pokenode *temp;
    // traversing the list and destroying each pokemon
    while (p != NULL) {    
        destroy_pokemon(p->pokemon);
        temp = p->next;
        free(p);
        p = temp;
    }
    free(pokedex);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {

    struct pokenode *p = pokedex->head;
    int id;
    int parameter = 0;
    // Check wheather there are pokemon between 0 and the factor
    while (p != NULL) {
        if (pokemon_id(p->pokemon) > 0 && pokemon_id(p->pokemon) < factor) {
            parameter = 1;
            break;
        }
        p = p->next;
    }
    
    if (parameter == 0) {
        printf("There aren't any Pokemon to find with pokemon_id between 0 and %d!\n", factor-1);
        exit(1);
    }
    
    // Seed the random number generator
    srand(seed);
    // randomly setting 'how_many' pokemon to found
    // Duplication allowed
    for (int i = 0; i < how_many; i++) {
        id = rand() % factor; 
        p = pokedex->head;
        while (p != NULL) {
            if (pokemon_id(p->pokemon) == id) { 
                p->found = 1;
                break;
            }
            p = p->next;
        }
        if (p == NULL)
            i--;        
    }
}

int count_found_pokemon(Pokedex pokedex) {

    struct pokenode *p = pokedex->head;
 
    int counter = 0;
    // Traverse the list and count all found pokemon until we get to the top
    while (p != NULL) {
        if (p->found == 1)
            counter++;
        p = p->next;
    }
    return counter; 
}

int count_total_pokemon(Pokedex pokedex) {

    struct pokenode *p = pokedex->head;
    int counter = 0;
    // Traverse the list and count all pokemon
    while (p != NULL) {
        counter++;
        p = p->next;      
    }
    return counter;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {

    struct pokenode *p = pokedex->head;
    struct pokenode *q = pokedex->head;
    // Finding from_id pokemon in list
    while (p != NULL) {
        if (pokemon_id(p->pokemon) == from_id) { 
            break;
        }  
        p = p->next;
    }
    // Finding to_id pokemon in list 
    while (q != NULL) {
        if (pokemon_id(q->pokemon) == to_id) {
            break;
        }
        q = q->next;
    }
    // Checking if pokemon exists or that they are different pokemon
    if (p == NULL || q == NULL || p == q) {
        printf("Invalid pokemon evolution\n");
        exit(1);
    }
    p->next_evo = q;
}

void show_evolutions(Pokedex pokedex) {

    struct pokenode *p = pokedex->current;
    // Case for empty pokedex     
    if (p == NULL) { 
        return;
    }
    
    int id, counter = 0;
    int n = count_total_pokemon(pokedex); 
    char *name; 
    const char *type_one, *type_two; 
    // do while loop to print evolution (when counter < 2n)      
    do {
        id = pokemon_id(p->pokemon);
        name = pokemon_name(p->pokemon);
        type_one = pokemon_type_to_string(pokemon_first_type(p->pokemon));
        type_two = pokemon_type_to_string(pokemon_second_type(p->pokemon));

        if (p->found == 1) {
            if (pokemon_second_type(p->pokemon) == NONE_TYPE) {
                printf("#%03d %s [%s]", id, name, type_one); 
            } else {
                printf("#%03d %s [%s %s]", id, name, type_one, type_two);
            } 
        }
        if (p->found == 0) {
            printf("#%03d ???? [????]", id ); 
        }
        p = p->next_evo;
        if (p != NULL) {
            printf(" --> ");   
        } 
        counter++;     
    } while (p != NULL && counter < 2*n);
    // If there is an evolution cycle (a -> b, b -> a);
    if (counter == 2*n) { 
        printf("Something really weird is going on...\n");
    }
    printf("\n");
} 

int get_next_evolution(Pokedex pokedex) {
 
    struct pokenode *p = pokedex->current;
    
    if (p == NULL) {
        fprintf(stderr, "Pokedex is empty. Exiting.\n");
        exit(1);
    }
    if (p->next_evo == NULL) {
        return DOES_NOT_EVOLVE;
    }
    return pokemon_id(p->next_evo->pokemon);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
   
    Pokedex same_type_pokedex = new_pokedex();
    struct pokenode *p = pokedex->head; 
    struct pokenode *p_prev = NULL;
    pokemon_type type_one, type_two;
    Pokemon newpokemon;
    // Traverse to the top of the list
    while (p != NULL) {
        p_prev = p;
        p = p->next;    
    }   
    p = p_prev;
    // Clone pokemon with same type to new pokedex
    while (p != NULL) {
        type_one = pokemon_first_type(p->pokemon);
        type_two = pokemon_second_type(p->pokemon);
        if (p->found == 1) {
            if (type_one == type || type_two == type) {
                newpokemon = clone_pokemon(p->pokemon);
                add_pokemon(same_type_pokedex, newpokemon);
            } 
        }
        p = p->previous;
    }
    p = same_type_pokedex->head;
    while (p != NULL) {
        p->found = 1;
        p->next_evo = NULL;
        same_type_pokedex->current = p;
        p = p->next;   
    }
    return same_type_pokedex;
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokemon new_pokemon = NULL;
    Pokedex found_pokedex = new_pokedex();
    struct pokenode *p = pokedex->head;
    // Clone all found pokemon to new pokedex
    while (p != NULL) {
        if (p->found == 1) {
            new_pokemon = clone_pokemon(p->pokemon);
            insertOrdered(found_pokedex, new_pokemon);
        }
        p = p->next;
    }
    p = found_pokedex->head;
    while (p != NULL) {
        p->found = 1;
        p->next_evo = NULL;
        found_pokedex->current = p;
        p = p->next;
    }
    return found_pokedex;
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {

    Pokemon new_pokemon = NULL;
    Pokedex substring_pokedex = new_pokedex();
    struct pokenode *p = pokedex->head;
    struct pokenode *p_prev = NULL;
    char *string;

    // traversing through to the top of the list
    while (p != NULL) {
        p_prev = p;
        p = p->next;       
    }
    p = p_prev;
    while (p != NULL) {
        if (p->found == 1) {
            string = pokemon_name(p->pokemon);
            if (checkSubstring(string, text)) {
                new_pokemon = clone_pokemon(p->pokemon);
                add_pokemon(substring_pokedex, new_pokemon);
            }
        }
        p = p->previous;
    }
    p = substring_pokedex->head;
    while (p != NULL) {
        p->found = 1;
        p->next_evo = NULL;
        p = p->next;
    }
    return substring_pokedex;
}

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.

static void print_astr(char *string) {
    for (int i = 0; string[i] != '\0' && string[i] != '\n'; i++)
        putchar('*');
}


static int get_found(Pokedex pokedex)  {
    return pokedex->current->found;
}


static void insertOrdered(Pokedex pokedex, Pokemon pokemon)  {

    struct pokenode *p = pokedex->head;
    struct pokenode *p_prev = NULL;
    int id = pokemon_id(pokemon);
    // find insertion point
    while (p != NULL && id < pokemon_id(p->pokemon))  {
        p_prev = p;
        p = p->next;
    }

    struct pokenode *newNode;
    newNode = malloc(sizeof(struct pokenode));
    if (newNode == NULL) {
        printf("Malloc failed, out of memory\n");
        exit(1);
    }
    newNode->previous = NULL;
    newNode->next = NULL;
    newNode->pokemon = pokemon;
    
    if (p_prev == NULL) {  //Insert at top of list 
        add_pokemon(pokedex, pokemon);
        find_current_pokemon( pokedex);
        free(newNode);
        return;
    } else  if (p !=NULL) {   // insert after p_prev and before p
        p_prev->next = newNode;
        newNode->previous = p_prev;
        newNode->next = p;
        p->previous = newNode;
        return;
    }
    if (p==NULL) {
        p_prev->next = newNode;
        newNode->previous = p_prev;

    }
}


// Return true, ie 1, if substring is contained within string
int checkSubstring(char *string, char *substring) {
    char lower_string[50]={0};
    char lower_substring[50]={0};
    int i,j,flg;

    // convert string to lowercase   
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            lower_string[i] = string[i] + 32;
        } else {
            lower_string[i] = string[i];
        }
    }
    lower_string[i] = '\0';

    // convert substring to lowercase
    for (j = 0; substring[j] != '\0'; j++) {
        if (substring[j] >= 'A' && substring[j] <= 'Z') {
            lower_substring[j] = substring[j] + 32; 
        } else {
            lower_substring[j] = substring[j];
        }   
    }
    lower_substring[j] = '\0';
    
    // if substring is longer than string return false
    if( j > i)
        return 0;
    
    for( int a = 0; lower_string[a]!='\0'; a++)  {
        flg = 1;
        for( int b = 0; b < j; b++ )  { 
            // return 0 if a+b > i, all elements is lower_string
            // have been accesed since lower_string has length i
            if (a+b > i)
                return 0;
            if (lower_string[a+b] != lower_substring[b]) {
                flg = 0;
                break;
            }
        } // if for b loop executed to completion, match found, return true
        if( flg == 1 )
            return 1;
    }
    // return false if no match found
    return 0;    
}
