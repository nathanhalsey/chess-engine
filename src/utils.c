#include"headers.h"
int pop_count(U64 board)
{
    int count = 0;
    while(board){
        count++;
        board &= (board - 1);
    }
    return count;
}
int lsb_index(U64 board)
{
    board = (board & - board) - 1;
    return pop_count(board);
}