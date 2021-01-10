#include"headers.h"
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