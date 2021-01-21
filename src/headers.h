#ifndef HEADERDEF
#define HEADERDEF
//INCLUDES GO HERE
#include<stdio.h>
#include"board.h"

///////////////////         ATTACKS              //////////////////////////////////

//attacks.c
U64 pawn_attacks(int,int);
U64 knight_attacks(int);
U64 bishop_attacks(int,U64);
U64 rook_attacks(int,U64);
U64 queen_attacks(int,U64);
U64 king_attacks(int);
void init_leapers(void);


/////////////////////////////////////////////////////////////////////////////////////////////////////

//output_functions.c
void print_board(U64);
void print_attacks(void);  


//utils.c
int popCount(U64);

//main.c
int main();


#endif //HEADERDEF
