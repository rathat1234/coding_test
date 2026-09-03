#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s), z_count = 0, mount = 0;
    char *s_copy = (char*)malloc(len+1);
    strcpy(s_copy,s);
    
    while(!(len == 1 && s_copy[0] == '1'))
    {
        int temp = 0;
        
        for(int i = 0 ; i < len ; i++)
        {
            
            if(s_copy[i] == '0')
            {
                z_count += 1;
            }
            else
            {
                temp += 1;
            }
        }
    
        int index = 0;

        while(temp > 0)
        {
            s_copy[index] = (temp % 2) + '0';
            temp /= 2;
            index++;
        }

        for(int i = 0; i < index / 2; i++)
        {
            char temp_char = s_copy[i];

            s_copy[i] = s_copy[index - 1 - i];
            s_copy[index - 1 - i] = temp_char;
        }

        s_copy[index] = '\0';
        len = index;

        mount += 1;
    }
    int* answer = (int*)malloc(sizeof(int)*2);
    answer[0] = mount;
    answer[1] = z_count;
    
    free(s_copy);
    return answer;
}