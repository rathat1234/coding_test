#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// elements_len은 배열 elements의 길이입니다.
int solution(int elements[], size_t elements_len) {
    int answer = 0;
    int max = 0;
    
    for(int i = 0; i < elements_len; i++)
    {
        max += elements[i];
    }
    
    int* check = calloc(max +1, sizeof(int));
    
    for(int i = 1; i <= elements_len; i++)
    {
        for(int j = 0; j < elements_len; j++)
        {
            int sum = 0;
            
            for(int k = 0; k < i; k++)
            {
                int index = (j + k) % elements_len;
                sum += elements[index];
            }
            
            if(check[sum]==0)
            {
                check[sum]=1;
                answer++;
            }
        }
    }
    
    free(check);
    
    return answer;
}