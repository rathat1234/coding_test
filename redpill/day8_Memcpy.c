#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
#include <stdbool.h>
#include <string.h>

int count = 1;

void bit_print(uint8_t *pixel, int size);
void l_memmove(uint8_t *dest, uint8_t *src, int size);
void r_memmove(uint8_t *dest, uint8_t *src, int size);
void print_template(uint8_t *pixel, int size, bool isRight,int shiftnum);
int main(int argc, char const *argv[])
{
    uint8_t dest1[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
    uint8_t dest2[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};

    int size = sizeof(dest1)/sizeof(uint8_t);

    printf("=== Day 8: Safe Memcpy (memmove) Implementation ===\r\n");
    printf("[Initial] ");
    bit_print(dest1,size);
    printf("\r\n\r\n");

    print_template(dest1, size,true,2);

    printf("[Initial] ");
    bit_print(dest1,size);
    printf("\r\n\r\n");
    print_template(dest2,size,false,2);
}
void bit_print(uint8_t *pixel, int size){
    for(int i=0; i < size ; i++)
    {
        printf("%02x ",*(pixel+i));
    }
}

void r_memmove(uint8_t *dest, uint8_t *src, int size)
{
    for (int i = size-1; i >= 0; i--)
    {
        dest[i] = src[i];
    }
}

void l_memmove(uint8_t *dest, uint8_t *src, int size)
{
    for (int i = 0; i <= size-1; i++)
    {
        dest[i] = src[i];
    }
}

void print_template(uint8_t *pixel, int size,bool isRight,int shiftnum)
{
    
    if(isRight)
    {
        printf("Test %d: Overlap (Dest > Src) -> Shift Right 2 bytes\r\n", count,shiftnum);
        printf("[result ] ");
        r_memmove((pixel+2), pixel,5);
        bit_print(pixel, size);
        printf("\r\n>> Success!\r\n\r\n");
    }
    else
    {
        printf("Test %d: Overlap (Dest < Src) -> Shift Left %d bytes\r\n", count,shiftnum);
        printf("[result ] ");
        l_memmove((pixel), (pixel+2),5);
        bit_print(pixel, size);
        printf("\r\n>> Success!\r\n");
    }
    count++;
}

