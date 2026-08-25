#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
#include <stdbool.h>
#include <string.h>

typedef struct info
{
    char name[4];
    int num;
}info;

void val_swap(void *a, void *b ,int size);

int main(int argc, char const *argv[])
{
    int int_a = 10, int_b = 20, size = 0;
    double db_a = 3.14159, db_b = 99.99000;
    info info_a = {"Kim",1}, info_b = {"Lee",2};

    printf("=== Day 9: Generic Swap Implementation ===\r\n\r\n");
    
    printf("[Int] Before    : %d, %d\r\n", int_a, int_b);
    size = sizeof(int_a);
    val_swap(&int_a,&int_b,size);
    printf("[Int] After     : %d, %d\r\n\r\n", int_a, int_b);

    printf("[Double] Before : %lf, %lf\r\n", db_a, db_b);
    size = sizeof(db_a);
    val_swap(&db_a,&db_b,size);
    printf("[Double] After  : %lf, %lf\r\n\r\n", db_a, db_b);

    printf("[Struct] before : %s(%d), %s(%d)\r\n", 
        info_a.name,info_a.num, info_b.name,info_b.num);
    size = sizeof(info);
    val_swap(&info_a,&info_b,size);
    printf("[Struct] After  : %s(%d), %s(%d)\r\n\r\n", 
        info_a.name,info_a.num, info_b.name,info_b.num);
}

void val_swap(void *a, void *b ,int size)
{
    unsigned char temp;
    unsigned char *temp_a = (unsigned char*)a;
    unsigned char *temp_b = (unsigned char*)b;
    for (int i = 0 ; i < size ; i++)
    {
        temp = temp_a[i];
        temp_a[i] = temp_b[i];
        temp_b[i] = temp;
    }

}