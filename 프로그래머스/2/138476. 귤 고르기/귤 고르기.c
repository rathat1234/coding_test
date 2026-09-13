#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// tangerine_len은 배열 tangerine의 길이입니다.

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2)
        return -1;
    else if(num1 > num2)
        return 1;

    return 0;
}

int compare2(const void *a, const void *b)
{
    long long num1 = *(long long *)a;
    long long num2 = *(long long *)b;

    if(num1 < num2)
        return 1;
    else if(num1 > num2)
        return -1;

    return 0;
}

int solution(int k, int tangerine[], size_t tangerine_len) {
    long long pair_num[tangerine_len];
    long long answer = 0, index = 0;

    memset(pair_num,  0 ,sizeof(pair_num));
    
    qsort(tangerine, tangerine_len, sizeof(int), compare);
    
    int temp = 1;
    
    for(int i = 0; i < tangerine_len - 1; i++)
    {
        if(tangerine[i] == tangerine[i + 1])
        {
            temp++;
        }
        else
        {
            pair_num[index] = temp;
            index++;
            temp = 1;
        }
    }
    
    pair_num[index] = temp;
    index++;
    
    qsort(pair_num, index, sizeof(long long), compare2);
    
    temp = 0;
    
    for(int i = 0; i < index; i++)
    {
        temp += pair_num[i];
        answer++;

        if(temp >= k)
            break;
    }
    
    return answer;
}