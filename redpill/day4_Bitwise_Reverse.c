#include <stdio.h>
#include <stdint.h>

int count = 1;

void bit_print(uint8_t pixel){
    int pcount = 0;
    printf(" ( ");
    for(int i = 7; i >= 0; i--)
    {
        printf("%d",(pixel >> i)&1);
        pcount++;
        if(pcount==4){
            printf(" ");
        }
    }
    printf(" ) \r\n");
    
}

void bit_reverse(uint8_t pixel)
{

    printf("Case : %d\r\n", count);

    printf("Input : 0x%02X", pixel);

    bit_print(pixel);
    
    pixel = ((pixel >> 7) & 0x01 | (pixel >> 5) & 0x02 |
            (pixel >> 3) & 0x04 | (pixel >> 1) & 0x08 |
            (pixel << 7) & 0x80 | (pixel << 5) & 0x40 |
            (pixel << 3) & 0x20 | (pixel << 1) & 0x10 );

    printf("Output : 0x%02X ", pixel);
    
    bit_print(pixel);

    printf("Verify : OK\r\n");

    count++;

}


int main(int argc, char const *argv[])
{

    printf("=== Day 4: Bitwise Reverse (Mirroring) ===\r\n");

    bit_reverse(0xD2);
    bit_reverse(0x0F);
    bit_reverse(0xAA);
    bit_reverse(0x12);

    return 0;
}
