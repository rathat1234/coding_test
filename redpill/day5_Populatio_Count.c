#include <stdio.h>
#include <stdint.h>
#include <intrin.h>

int count = 1;

void print_text(uint32_t pixel);
int naive_count(uint32_t pixel, int num);
int kernighan_count(uint32_t pixel);
int swar_count(uint32_t pixel);

int main(int argc, char const *argv[])
{

    printf("=== Day 5: Population Count (Counting Set Bits) ===\r\n");

    print_text(0x00000000);
    print_text(0x00000007);
    print_text(0x12345678);
    print_text(0xFFFFFFFF);

    return 0;
}

void print_text(uint32_t pixel)
{
    int num = 0, n_count = 0, k_count = 0, s_count = 0, b_count = 0;
    
    printf("Case %d : Input : 0x%08X\r\n", count, pixel);

    n_count = naive_count(pixel, num);
    k_count = kernighan_count(pixel);
    s_count = swar_count(pixel);
    b_count = __popcnt(pixel);

    printf("[Naive]     : %d\r\n", n_count);
    printf("[Kernighan] : %d\r\n", k_count);
    printf("[SWAR]      : %d\r\n", s_count);
    printf("[Built-in]  : %d\r\n", b_count);

    count++;
    printf("------------------------------\r\n");
}

int naive_count(uint32_t pixel, int num)
{
    if (num == 31)
    {
        if (((pixel >> num) & 1) == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        if (((pixel >> num) & 1) == 1)
            return 1 + naive_count(pixel, num + 1);
        else
            return 0 + naive_count(pixel, num + 1);
    }
}

int kernighan_count(uint32_t pixel)
{
    if (pixel != 0)
    {
        return 1 + kernighan_count(pixel &= pixel - 1);
    }
    else
    {
        return 0;
    }
}

int swar_count(uint32_t pixel)
{
    pixel = pixel - ((pixel >> 1) & 0x55555555);
    pixel = (pixel & 0x33333333) + ((pixel >> 2) & 0x33333333);
    pixel = (pixel & 0x0F0F0F0F) + ((pixel >> 4) & 0x0F0F0F0F);
    pixel = (pixel & 0x00FF00FF) + ((pixel >> 8) & 0x00FF00FF);
    pixel = (pixel & 0x0000FFFF) + ((pixel >> 16) & 0x0000FFFF);


    return pixel;
}


