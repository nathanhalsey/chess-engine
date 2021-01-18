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
U64 knight_attacks(int square, U64 blockers)
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
U64 bishop_attacks(int square, U64 blockers)
{

    int can_go_right_up = !in_h((int)square) && !in_one((int)square);
    int can_go_right_down = !in_h((int)square) && !in_eight((int)square);
    int can_go_left_up = !in_a((int)square) && !in_one((int)square);
    int can_go_left_down = !in_a((int)square) && !in_eight((int)square);

    U64 board = 0ULL;
    U64 attacks = 0ULL;
    put(board,square);
    for (int i = 1; i < 8; i++){
        if ((!get(blockers,(int)(square + (i-1)*7)) && can_go_left_down) && (!in_a((int)(square+(i-1)*7)) && !in_eight((int)(square + (i-1)*7)))){
            attacks |= (board << i*7);
        } else {
            can_go_left_down = 0;
        }
        if ((!get(blockers,(int)(square-(i-1)*9)) && can_go_left_up) && (!in_a((int)(square-(i-1)*9)) && !in_one((int)(square-(i-1)*9)))){
            attacks |= (board >> i*9);
        } else {
            can_go_left_up = 0;
        }
        if ((!get(blockers,(int)(square - (i-1)*7)) && can_go_right_up) && (!in_h((int)(square -(i-1)*7)) && !in_one((int)(square - (i-1)*7)))){
            attacks |= (board >> i*7);
        } else {
            can_go_right_up = 0;
        }
        if ((!get(blockers,(int)(square+(i-1)*9)) && can_go_right_down) && (!in_h((int)(square+(i-1)*9)) && !in_eight((int)(square+(i-1)*9)))){
            attacks |= (board << i*9);
        } else {
            can_go_right_down = 0;
        }
    }
    return attacks;
}
//generate rook attacks (completed, working)
U64 rook_attacks(int square, U64 blockers)
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
        if ((!get(blockers,(int)(square-(i-1)*8)) && can_go_up) && !in_one((int)(square-(i-1)*8))){
            attacks |= (board >> i*8);
        } else {
            can_go_up = 0;
        }
        //right
        if ((!get(blockers,(int)(square+(i-1))) && can_go_right) && !in_h((int)(square+(i-1)))){
            attacks |= (board << i);
        } else {
            can_go_right = 0;
        }
        //left
        if ((!get(blockers,(int)(square-(i-1))) && can_go_left) && !in_a((int)(square - (i-1)))){
            attacks |= (board >> i);
        } else {
            can_go_left = 0;
        }
        //down
        if ((!get(blockers,(int)(square+(i-1)*8)) && can_go_down) && !in_eight((int)(square+(i-1)*8))){
            attacks |= (board << i*8);
        } else {
            can_go_down = 0;
        }
    }
    return attacks;
}
// generate queen attacks (working, completed)
U64 queen_attacks(int square, U64 blockers)
{
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    attacks |= rook_attacks(square,blockers);
    attacks |= bishop_attacks(square,blockers);

    return attacks;
}
U64 king_attacks(int square,U64 blockers)
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
    //down-left (verified)
    if (!in_a((int)square) && !in_eight((int)square)){
        attacks |= (board << 7);
    }
    //down-right (verified)
    if (!in_h((int)square) && !in_eight((int)square)){
        attacks |= (board << 9);
    }
    //up-left (verified)
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
        knight_attack_vectors[i] = knight_attacks(i,0ULL);
        bishop_attack_vectors[i] = bishop_attacks(i,0ULL);
        rook_attack_vectors[i] = rook_attacks(i,0ULL);
        queen_attack_vectors[i] = queen_attacks(i,0ULL);
        king_attack_vectors[i] = king_attacks(i,0ULL);
    }
}
void print_attack_vectors()
{
    U64 blockers;
    put(blockers,E5);
    put(blockers,B2);
    put(blockers,G7);
    put(blockers,B6);
    put(blockers,E4);
    printf("Blocker on %d ?, %d\n",F2,get(blockers,F2));
    print_board(blockers);
    print_board(rook_attacks(B4,blockers));
    print_board(bishop_attacks(D4,blockers));
}