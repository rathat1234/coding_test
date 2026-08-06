#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int temp = 1;
    int mul = 1;

    for (int i = 0; i < strlen(s) - 1; i++)
    {
        mul *= 10;
    }
    
    if(s[0]=='-')
    {
        temp = -1;
        mul /= 10;
        
    }
    else if(s[0]=='+')
    {
        temp = 1;
        mul /= 10;
        
    }
    else
    {
        answer += mul*(s[0]-48);
        mul /= 10;
    }
    
    for(int i = 1; i<=strlen(s);i++)
    {
        answer += mul * (s[i]-48);
        mul /= 10;
    }
    answer *= temp;
    return answer;
}