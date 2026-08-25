#include "stdio.h"
#include "stdbool.h"

#define NOISE_SIZE 10
#define NOISE_SAMPLE 3

void count_noise(int *switch_noise);
void print_row(int noise);


int main(int argc, char const *argv[])
{
    int switch_noise[NOISE_SIZE] = { 0,0,1,0,1,1,1,1,1,0 }; 

    printf("=== Day 24: Button Debouncing Logic ===\r\n");
    printf("Condition: 3 consecutive samples required.\r\n\r\n");

    count_noise(switch_noise);
    return 0;
}

void count_noise(int *switch_noise){

    printf("Step | Raw Input | Counter | Output (Stable)\r\n");
    printf("--------------------------------------------\r\n");
    for (int i = 0; i < NOISE_SIZE; i++)
    {
        print_row(switch_noise[i]);
    }
}

void print_row(int noise)
{
    static int step = 1; 
    static int count_noise = 0;
    static int output = 0;
    static int prev = 0;

    if(noise!=output)
    {
        if(noise==prev)
        {
            prev = noise;
            count_noise++;
            if(count_noise>=3)
            {
                if(output==0) output = 1;
                else output = 0;
                printf("  >> [State Changed] to %d\r\n",output);
                count_noise = 0;
            }
        }
        else 
        {
            prev= noise;
            count_noise = 1;
        }
    }
    else count_noise = 0;
    printf("%3d | %9d | %8d | %9d\r\n",step,noise,count_noise,output);
    step++;
}