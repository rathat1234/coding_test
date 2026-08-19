#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    int len = strlen(s);
    int cnt = 0;
    for(int i = 0 ; i <= len ; i++)
    {
        if(s[i]=='(') 
        {
            cnt++;
        }
        else if(s[i]==')') 
        {
            if(cnt == 0 && i == 0)
            {
                answer = false;
                break;
            }
            else if (cnt==0)
            {
                answer = false;
                break;
            }
            cnt--;
        }
    }
    if(cnt != 0) answer = false;
    return answer;
}