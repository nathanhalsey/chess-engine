#include"headers.h"
void print_attacks()
{
    U64 board = king_attacks(A6);
    print_board(board);
    int count = pop_count(board);
    printf("Popcount is: %d\n",count);
    char* my_coord = int_to_coord(lsb_index(board));
    printf("LSB square is: %s\n",my_coord);
    //print_board(board);
}
void print_board(U64 board)
{
    printf("  A B C D E F G H\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j ++)
        {
            if (j == 0)
            {
                printf("%d ",i+1);
            }
            int square = i * 8 + j;
            printf("%d ", get(board,square) ? 1 : 0);
        }
        printf("\n");
    }

}