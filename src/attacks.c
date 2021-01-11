#include"headers.h"
U64 pawn_attack_vectors[64][2];
U64 knight_attack_vectors[64][2];
U64 bishop_attack_vectors[64][2];
U64 rook_attack_vectors[64][2];
U64 queen_attack_vectors[64][2];
U64 king_attack_vectors[64][2];  
U64 pawn_attacks(int square, int colour)
{
    U64 board = 0ULL;
    U64 attacks = 0ULL;
    put(board,square);
    if (colour == 0) { // white pawns
        // if the square is in the A column, then there is no left attack vector
        if (!in_a((int)square)){
            attacks |= (board << 7);
        }
        if (!in_h((int)square)){
            attacks |= (board << 9);
        }
    }
    else { //black pawns
        if (!in_h((int)square)){
            attacks |= (board >> 7);   
        }
        if (!in_a((int)square)){
            attacks |= (board >> 9);
        }
    }
    return attacks;
}
void init_attack_vectors()
{
    for (int i = 0; i < 64; i++){
        //init pawn attacks
        pawn_attack_vectors[i][white] = pawn_attacks(i,white);
        pawn_attack_vectors[i][black] = pawn_attacks(i,black);
    }
}
void print_attack_vectors()
{
    for (int i = 0; i < 64; i++){
        print_board(pawn_attack_vectors[i][white]);
    }
}