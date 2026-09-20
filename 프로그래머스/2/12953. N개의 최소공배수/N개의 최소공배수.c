#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int divisor_num(int num1, int num2)
{
    while(num2 != 0)
    {
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }

    return num1;
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len)
{
    int answer = arr[0];

    for(int i = 1 ; i < arr_len ; i++)
    {
        int divisor = divisor_num(answer, arr[i]);

        answer = answer * arr[i] / divisor;
    }

    return answer;
}