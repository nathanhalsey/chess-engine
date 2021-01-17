#include"headers.h"
U64 pawn_attack_vectors[64][2];
U64 knight_attack_vectors[64];
U64 bishop_attack_vectors[64];
U64 rook_attack_vectors[64];
U64 queen_attack_vectors[64];
U64 king_attack_vectors[64];
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
    if (!in_one_two((int)square) && !in_a((int)square)){
        attacks |= (board >> 17);
    }
    if (!in_one_two((int)square) && !in_h((int)square)){
        attacks |= (board >> 15);
    }
    if (!in_seven_eight((int)square) && !in_a((int)square)){
        attacks |= (board << 15);
    }
    if (!in_seven_eight((int)square) && !in_h((int)square)){
        attacks |= (board << 17);
    }
    if (!in_ab((int)square) && !in_eight((int)square)){
       attacks |= (board << 6);
    }
    if (!in_ab((int)square) && !in_one((int)square)){
        attacks |= (board >> 10);
    }
    if (!in_gh((int)square) && !in_one((int)square)){
        attacks |= (board >> 6);
    }
    if (!in_gh(square) && !in_eight((int)square)){
        attacks |= (board << 10);
    }
    return attacks;
}
// generate bishop attacks (completed, working)
U64 bishop_attacks(int square)
{

    int can_go_right_up = !in_h((int)square) && !in_one((int)square);
    int can_go_right_down = !in_h((int)square) && !in_eight((int)square);
    int can_go_left_up = !in_a((int)square) && !in_one((int)square);
    int can_go_left_down = !in_a((int)square) && !in_eight((int)square);

    U64 board = 0ULL;
    U64 attacks = 0ULL;
    put(board,square);

    for (int i = 1; i < 8; i++){
        if (can_go_left_down && !in_a((int)(square+(i-1)*7)) && !in_eight((int)(square + (i-1)*7))){
            attacks |= (board << i*7);
        } else {
            can_go_left_down = 0;
        }
        if (can_go_left_up && !in_a((int)(square-(i-1)*9)) && !in_one((int)(square-(i-1)*9))){
            attacks |= (board >> i*9);
        } else {
            can_go_left_up = 0;
        }
        if (can_go_right_up && !in_h((int)(square -(i-1)*7)) && !in_one((int)(square - (i-1)*7))){
            attacks |= (board >> i*7);
        } else {
            can_go_right_up = 0;
        }
        if (can_go_right_down && !in_h((int)(square+(i-1)*9)) && !in_eight((int)(square+(i-1)*9))){
            attacks |= (board << i*9);
        } else {
            can_go_right_down = 0;
        }
    }
    return attacks;
}
//generate rook attacks (completed, working)
U64 rook_attacks(int square)
{
    int can_go_up = !in_one((int)square);
    int can_go_down = !in_eight((int)square);
    int can_go_left = !in_a((int)square);
    int can_go_right = !in_h((int)square);
    
    U64 board = 0ULL;
    U64 attacks = 0ULL;
    put(board,square);

    for (int i = 1; i < 8; i++){
        //up
        if (can_go_up && !in_one((int)(square-(i-1)*8))){
            attacks |= (board >> i*8);
        } else {
            can_go_up = 0;
        }
        //right
        if (can_go_right && !in_h((int)(square + (i-1)))){
            attacks |= (board << i);
        } else {
            can_go_right = 0;
        }
        //left
        if (can_go_left && !in_a((int)(square - (i-1)))){
            attacks |= (board >> i);
        } else {
            can_go_left = 0;
        }
        //down
        if (can_go_down && !in_eight((int)(square+(i-1)*8))){
            attacks |= (board << i*8);
        } else {
            can_go_down = 0;
        }
    }
    return attacks;
}
// generate queen attacks (working, completed)
U64 queen_attacks(int square)
{
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    attacks |= rook_attacks(square);
    attacks |= bishop_attacks(square);

    return attacks;
}
U64 king_attacks(int square)
{
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    put(board,square);
    //right (verified)
    if (!in_h((int)square)){
        attacks |= (board << 1);
    }
    //left (verified)
    if (!in_a((int)square)){
        attacks |= (board >> 1);
    }
    //up (verified)
    if(!in_one((int)square)){
        attacks |= (board >> 8);
    }
    //down (verified)
    if (!in_eight((int)square)){
       attacks |= (board << 8);
    }
    //down-left (verified)ss
    // NOT WORKING
    if (!in_a((int)square) && !in_eight((int)square)){
        attacks |= (board << 7);
    }
    //down-right (verified)
    if (!in_h((int)square) && !in_eight((int)square)){
        attacks |= (board << 9);
    }
    //up-left (verified)
    // not working
    if (!in_a((int)square) && !in_one((int)square)){
        attacks |= (board >> 9);
    }
    //up-right (verified)
    if (!in_h((int)square) && !in_one((int)square)){
        attacks |= (board >> 7);
    }
    return attacks;
}
void init_attack_vectors()
{
    for (int i = 0; i < 64; i++){
        pawn_attack_vectors[i][white] = pawn_attacks(i,white);
        pawn_attack_vectors[i][black] = pawn_attacks(i,black);
        knight_attack_vectors[i] = knight_attacks(i);
        bishop_attack_vectors[i] = bishop_attacks(i);
        rook_attack_vectors[i] = rook_attacks(i);
        queen_attack_vectors[i] = queen_attacks(i);
        king_attack_vectors[i] = king_attacks(i);
    }
}
void print_attack_vectors()
{
    for (int i = 0; i < 64; i++){
        printf("Board: %d\n",i);
        print_board(king_attack_vectors[i]);
    }
    print_board(king_attacks(D8));
}