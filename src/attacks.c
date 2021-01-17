#include"headers.h"
U64 pawn_attack_vectors[64][2];
U64 knight_attack_vectors[64];
U64 bishop_attack_vectors[64][2];
U64 rook_attack_vectors[64][2];
U64 queen_attack_vectors[64][2];
U64 king_attack_vectors[64][2];
// generate pawn attacks (completed, working)
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
// generate knight attacks (completed, working)
U64 knight_attacks(int square)
{
    U64 board = 0ULL;
    U64 attacks = 0ULL;
    put(board,square);
    if (!in_one_two(square) && !in_a(square)){
        attacks |= (board >> 17);
    }
    if (!in_one_two(square) && !in_h(square)){
        attacks |= (board >> 15);
    }
    if (!in_seven_eight(square) && !in_a(square)){
        attacks |= (board << 15);
    }
    if (!in_seven_eight(square) && !in_h(square)){
        attacks |= (board << 17);
    }
    if (!in_ab(square) && !in_eight(square)){
       attacks |= (board << 6);
    }
    if (!in_ab(square) && !in_one(square)){
        attacks |= (board >> 10);
    }
    if (!in_gh(square) && !in_one(square)){
        attacks |= (board >> 6);
    }
    if (!in_gh(square) && !in_eight(square)){
        attacks |= (board << 10);
    }
    return attacks;
}
U64 bishop_attacks(int square)
{

}
void init_attack_vectors()
{
    for (int i = 0; i < 64; i++){
        //init pawn attacks
        pawn_attack_vectors[i][white] = pawn_attacks(i,white);
        pawn_attack_vectors[i][black] = pawn_attacks(i,black);
        knight_attack_vectors[i] = knight_attacks(i);
    }
}
void print_attack_vectors()
{
    for (int i = 0; i < 64; i++){
        print_board(knight_attack_vectors[i]);
    }
    //print_board(knight_attacks(D1));
}