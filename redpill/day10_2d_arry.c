#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
#include <stdbool.h>
#include <string.h>

void array_set(int row, int col);

int main(int argc, char const *argv[])
{
    int row = 3, col = 4;

    printf("=== Day 10: Dynamic 2D Array Allocation ===\r\n\r\n");
    printf("Generated Matrix (%dx%d):\r\n",row,col);
    array_set(row,col);

}

void array_set(int row, int col)
{
    int* array = malloc(sizeof(int)*(row*col));
    int count = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int num = (i*col)+j;
            array[num]=count;
            count++;
        }
    }
    int **row_ptr = malloc(sizeof(int *)*(row));
    for (int i = 0; i < row; i++)
    {
        row_ptr[i] = &array[i*col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ",*row_ptr[i]+j);
        }
        printf("\r\n");
    }
    
    free(array);
    free(row_ptr);
    
    printf("\r\n>> Memory successfully freed");

}
