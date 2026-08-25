#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
#include <stdbool.h>

uint32_t red_pill(uint32_t pixel, int num, bool RDR);
void bit_print(uint32_t pixel);
uint32_t hex_ROL(uint32_t pixel, int num);
uint32_t hex_ROR(uint32_t pixel, int num);

uint32_t pixel;

int main(int argc, char const *argv[])
{
    pixel = 0xF0000000;
    uint32_t temp1;
    printf("=== Day 6: Circular Shift (Rotate) ===\r\n");

    printf("[Init]   Hex: 0x%08X\r\n", pixel);
    bit_print(pixel);
    printf("\n");

    temp1 = red_pill(pixel, 4 , true);
    red_pill(temp1, 4 , false);

    pixel = 0x12345678;
    temp1 = hex_ROR(pixel, 8);
    printf("[Test 2]   Hex: 0x%08X -> ROR %d -> 0x%08X", pixel, 8, temp1);
    return 0;
}

uint32_t red_pill(uint32_t pixel, int num, bool RDR)
{
    uint32_t temp2;
    if (RDR == true)
    {
        temp2 = hex_ROL(pixel, num);
        printf("[ROL %d]   Hex: 0x%08X\r\n", num, temp2);
        bit_print(temp2);
        printf("(MSB bits moved to LSB)\r\n\n");
    }
    else
    {
        temp2 = hex_ROR(pixel, num);
        printf("[ROR %d]   Hex: 0x%08X\r\n", num, temp2);
        bit_print(temp2);
        printf("(Restored to original)\r\n\n");
    }
    return temp2;
}

void bit_print(uint32_t pixel)
{
    printf("Bin: ");
    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (pixel >> i) & 1);
        count++;
        if (count % 4 == 0)
        {
            printf(" ");
        }
        else if (count == 0)
        {
            continue;
        }
    }
    printf("\r\n");
}

uint32_t hex_ROL(uint32_t pixel, int num)
{
    uint32_t temp = 0xFFFFFFFF;
    temp = temp << (32 - num);
    temp &= pixel;
    temp = (temp >> (32 - num));
    pixel = ((pixel << num) | temp);

    return pixel;
}

uint32_t hex_ROR(uint32_t pixel, int num)
{
    uint32_t temp = 0xFFFFFFFF;
    temp = temp >> (32 - num);
    temp &= pixel;
    temp = (temp << (32 - num));
    pixel = ((pixel >> num) | temp);

    return pixel;
}
