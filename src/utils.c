#include"headers.h"
int popCount(U64 board)
{
    int count = 0;
    while(board){
        count++;
        board &= (board - 1);
    }
    return count;
}