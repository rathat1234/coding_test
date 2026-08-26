#include "stdio.h"

#define WINDOW_SIZE 5
#define DATA_SIZE 10

float buffer[WINDOW_SIZE];

float moving_average(float data);

int main(int argc, char const *argv[])
{
    float sensor_data[DATA_SIZE] = {
        20.0, 22.0, 18.0, 25.0, 15.0,
        20.0, 21.0, 19.0, 20.5, 20.0
    };

    printf("=== Day 25: Moving Average Filter (Sliding Window) ===\r\n");
    printf("Window Size: %d\r\n\r\n", WINDOW_SIZE);

    printf("Step | Raw Input | Filtered Output\r\n");
    printf("-----+-----------+----------------\r\n");

    for(int i = 0; i < DATA_SIZE; i++)
    {
        float result = moving_average(sensor_data[i]);

        printf("%4d | %9.1f | %10.1f\r\n",
               i + 1, sensor_data[i], result);
    }

    return 0;
}

float moving_average(float data)
{
    static int index = 0;
    static int count = 0;
    static float sum = 0;

    float avg = 0;

    if(count != 0)
    {
        avg = sum / count;

        if(data < avg * 0.5 || data > avg * 1.5)
        {
            return avg;
        }
    }

    if(count < WINDOW_SIZE)
    {
        buffer[index] = data;
        sum += data;
        count++;
    }
    else
    {
        sum -= buffer[index];
        buffer[index] = data;
        sum += data;
    }

    index++;

    if(index >= WINDOW_SIZE)
    {
        index = 0;
    }

    avg = sum / count;

    return avg;
}