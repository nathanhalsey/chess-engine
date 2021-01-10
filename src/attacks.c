#include"headers.h"
U64 pawn_attacks(int square, int colour)
{
    U64 board = 0ULL;
    U64 attacks = 0ULL;
    put(board,square);
    if (colour == 0) //white pawns
    {
        if (!in_a((int)square)){
            attacks |= (board << 7);
        }
        if (!in_h((int)square)){
            attacks |= (board << 9);
        }
    }
    else //black pawns
    {
        printf("%d\n",(int)square);
        if (!in_h((int)square)){
            attacks |= (board >> 7);   
        }
        if (!in_a((int)square)){
            attacks |= (board >> 9);
        }
    }
    return attacks;
}
