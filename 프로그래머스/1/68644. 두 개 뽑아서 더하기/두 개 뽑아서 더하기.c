#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    int answer_len = 0, n = 0, num = 0;
    int temp_count = (numbers_len * (numbers_len-1))/2;
    
    int* temp = malloc(sizeof(int) * temp_count);
    
    bool f_flag = true;
    
    for(int i = 0 ; i < numbers_len ; i++)
    {
        for(int j = i + 1 ; j < numbers_len  ; j++)
        {
            temp[n] = numbers[i]+numbers[j];
            n++;
        }
    }
    
    answer_len = n;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n  ; j++)
        {
            if(temp[i]==temp[j])
            {
                if(temp[i] != -1)
                {
                    answer_len--;
                    temp[j] = -1;
                }
            }
        }
    }
    
    int* answer = malloc(sizeof(int)*answer_len);
    
    for(int i = 0 ; i < n ; i++)
    {
        if(temp[i]!=-1)
        {
            answer[num]=temp[i];
            num++;
        }
    }
    
    for(int i = 0 ; i < answer_len ; i++)
    {
        for(int j = i + 1 ; j < answer_len  ; j++)
        {
            int t_val = 0;
            if(answer[i]>answer[j])
            {
                t_val = answer[i];
                answer[i] = answer[j];
                answer[j] = t_val;
            }
        }
    }

    
    return answer;
}