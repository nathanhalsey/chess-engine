#ifndef BOARD_H
#define BOARD_H
#include<stdio.h>
#define U64 unsigned long long


// bitboard operation macros
#define get(board,square) (board & (1ULL << square))
#define put(board,square) (board |= (1ULL << square))
#define remove(board,square) (get(board,square) ? (board ^= (1ULL << square)) : 0)



// bitboard macros to return where we are on the board, used to deicde is a move is legal
#define in_a(square) (square%8 == 0)
#define in_b(square) ((square-1)%8 == 0)
#define in_h(square) ((square-7)%8  == 0)
#define in_g(square) ((square-6)%8 == 0)

#define in_one_two(square) (square < 16)
#define in_seven_eight(square) (square > 48)
#define in_eight(square) (square > 56)
#define in_one(square) (square < 8)
#define in_gh(square) (in_h(square) || in_g(square))
#define in_ab(square) (in_a(square) || in_b(square))


enum{
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
};
enum {
    white = 0, black = 1
};
enum {
    pawn = 1, knight = 2, bishop = 3, rook = 4, queen = 5, king = 6
};

//board.c (not currenlty used)
void __init__board();

#endif //BOARD_H