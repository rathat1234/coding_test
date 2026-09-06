#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int str_len = strlen(s);
    char* answer = (char*)malloc(str_len+1);
    
    strcpy(answer, s);
    int index = 1;
    for(int i = 0 ; i < str_len ; i++)
    {
        
        if(answer[i]==' '){
            index = 1;
            continue;
        }
            
        
        if(index % 2 == 1)
        {
            if(97 <= answer[i] && answer[i] <= 122)
            {
                answer[i] -= 32;
            }
        }
        else
        {
            if(65 <= answer[i] && answer[i] <= 90)
            {
                answer[i] += 32;
            }
        }
        index++;
 
    }
    return answer;
}