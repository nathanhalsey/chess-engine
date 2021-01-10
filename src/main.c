#include"headers.h"
int main(int argc, char const *argv[])
{
    print_board(pawn_attacks(A6,white));
    return 0;
}