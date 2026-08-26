#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define BUFFER_SIZE 20
#define BYTE_SIZE ((BUFFER_SIZE + 7) / 8 )

uint8_t buffer[BYTE_SIZE];

void indexInit();
int index_free(int num);
int index_alloc(int num);
void print_buffer(int size);


int main(int argc, char const *argv[])
{
    int size = 36;
    printf("=== Day 17: Bitmap Manager ===\r\n\r\n");

    indexInit();
    
    for (int i = 0; i < 8; i++)
    {
        index_alloc(i);
    }

    print_buffer(BUFFER_SIZE);

    printf("\r\n");
    printf("Freeing index 2...\r\n");
    index_free(2);
    print_buffer(BUFFER_SIZE);

    printf("\r\n");
    printf("Allocating again...\r\n");
    index_alloc(2);
    print_buffer(BUFFER_SIZE);

    return 0;
}

void indexInit()
{
    for(int i = 0; i < BYTE_SIZE; i++)
    {
        buffer[i] = 0;
    }
}

int index_free(int num)
{
    int byte = num / 8;
    int bit = num % 8;

    if(num < 0 || num >= BUFFER_SIZE)
    {
        return -1;
    }

    buffer[byte] &= ~(1 << bit);

    printf(">> Index %d freed. (Byte %d, Bit %d cleared)\r\n",
           num, byte, bit);

    return num;
    
}

int index_alloc(int num)
{
    int byte = num / 8;
    int bit = num % 8;

    if(num < 0 || num >= BUFFER_SIZE)
    {
        return -1;
    }

    if((buffer[byte] >> bit) & 1)
    {
        return -1;
    }

    buffer[byte] |= (1 << bit);

    printf(">> Index %d allocated. (Byte %d, Bit %d set)\r\n",
           num, byte, bit);

    return num;
}
void print_buffer(int size)
{
    int count = 1;
    printf("[Bitmap Visual] ");

    for(int i = 0; i < size; i++)
    {
        int byte = i / 8;
        int bit = i % 8;

        printf("%d", (buffer[byte] >> bit) & 1);
        count++;
        if(count>8 && i != size-1)
        {
            printf(" | ");
            count = 1;
        }
    }

    printf("\r\n");
}