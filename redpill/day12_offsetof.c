#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

#define my_offsetof(sample, val)  ((size_t)&(((sample *)0)->val))

typedef struct {
    char a;      // 1 byte
    int b;       // 4 bytes
    double c;    // 8 bytes
} Sample;

void print_offset(void);
void print_my_offset(void);

int main(int argc, char const *argv[])
{
    printf("=== Day 12: offsetof Implementation ===\r\n\r\n");

    int len = sizeof(Sample);
    printf("Struct Size: %d bytes\r\n\r\n",len);
    
    print_offset();
    
    printf("-------------------------------------\r\n\r\n");

    print_my_offset();

    printf(">> Success! Implementation is correct.\n\r\n");

    return 0;
}

void print_offset(void)
{
    int offset_temp=offsetof(Sample, a);
    printf("[Standard] Offset of a: %d\r\n", offset_temp);
    offset_temp=offsetof(Sample, b);
    printf("[Standard] Offset of b: %d\r\n", offset_temp);
    offset_temp=offsetof(Sample, c);
    printf("[Standard] Offset of c: %d\r\n\r\n", offset_temp);
}

void print_my_offset(void)
{
    int offset_temp=my_offsetof(Sample,a);
    printf("[My Macro] Offset of a: %d\r\n", offset_temp);
    offset_temp=my_offsetof(Sample, b);
    printf("[My Macro] Offset of b: %d\r\n", offset_temp);
    offset_temp=my_offsetof(Sample, c);
    printf("[My Macro] Offset of c: %d\r\n\r\n", offset_temp);
}