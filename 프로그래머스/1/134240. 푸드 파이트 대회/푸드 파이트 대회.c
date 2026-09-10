#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    int index = 0;
    int usage_half = 0;
    for(int i = 0 ; i < food_len ; i++)
    {
        usage_half += food[i]/2;
    }
    
    char* answer = malloc(sizeof(char) * ((usage_half * 2) + 2));
    
    for(int i = 0 ; i < usage_half;i++)
    {
        int temp = 0;
        
        for(int j = 1 ; j <= food_len ; j ++)
        {
            temp += food[j]/2;
            
            if(i<temp)
            {
                answer[index] = j + '0';
                break;
            }
                
        }

        
        index++;
    }
    
    answer[index] = '0';
    index++;
    
    for(int i = 0 ; i < usage_half;i++)
    {
        int temp = 0;
        
        for(int j = food_len-1 ; j >= 1 ; j --)
        {
            temp += food[j]/2;
            
            if(i<temp)
            {
                answer[index] = j + '0';
                break;
            }
                
        }

        
        index++;
    }
    answer[index] = '\0';
    
    return answer;
}