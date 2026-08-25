#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
    Add = 0,
    Sub,
    Mul,
    Div,
    Exit
} cal;

void cal_add(float,float);
void cal_sub(float,float);
void cal_mul(float,float);
void cal_div(float,float);
void act_calculating(void);

typedef void (*func_ptr)(float,float);

func_ptr cal_func[] = {cal_add, cal_sub, cal_mul, cal_div};
bool isRun = true;
int main(int argc, char const *argv[])
{
    printf("=== Day 11: Function Pointer Array Calculator ===\r\n\r\n");

    act_calculating();
}

void act_calculating(void)
{
    int cal_type;
    while(isRun){
        printf("Select (0:Add, 1:Sub, 2:Mul, 3:Div, 4:Exit):");
        scanf("%d", &cal_type);
        if(cal_type == 4) break;
        float a, b;
        printf("Input two integers:");
        scanf("%f %f", &a, &b);
        cal_func[cal_type](a,b);

    }
    
}

void cal_add(float a,float b)
{
    
    printf(">> Result : %.f\r\n\r\n", a + b);
}
void cal_sub(float a,float b)
{

    printf(">> Result : %.f\r\n\r\n", a - b);
}
void cal_mul(float a,float b)
{

    printf(">> Result : %.f\r\n\r\n", a * b);
}
void cal_div(float a,float b)
{

    if (b == 0)
    {
        printf("0으로 나눌수 없습니다.\r\n\r\n");
    }
    else
    {
        printf(">> Result : %.f\r\n\r\n", a / b);
    }
}
