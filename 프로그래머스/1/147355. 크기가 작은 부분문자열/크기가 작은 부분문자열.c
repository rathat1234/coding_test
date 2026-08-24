#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    int len = strlen(t);
    int part_len = strlen(p);
    char* temp = malloc(part_len+1);
    for(int i = 0 ; i <= len - part_len; i++)
    {
        memcpy(temp, t + i, part_len);
        temp[part_len] = '\0';
        long value = strtol(temp, NULL, 10);
        long target = strtol(p, NULL, 10);
        if(value<=target)
        {
            answer++;
        }
    }
    return answer;
}