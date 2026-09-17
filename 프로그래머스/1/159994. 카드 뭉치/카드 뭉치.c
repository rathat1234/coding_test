#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// cards1_len은 배열 cards1의 길이입니다.
// cards2_len은 배열 cards2의 길이입니다.
// goal_len은 배열 goal의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = malloc(sizeof(char)*4);
    int c1_index = 0;
    int c2_index = 0;
    int i = 0;
    
    for(i = 0; i < goal_len ; i++)
    {
        if(c1_index<cards1_len && strcmp(cards1[c1_index],goal[i])==0)
            c1_index++;
        else if(c2_index<cards2_len && strcmp(cards2[c2_index],goal[i])==0)
            c2_index++;
        else
        {
            break;
        }

    }
    
    if(i==goal_len)
        strcpy(answer,"Yes");
    else
        strcpy(answer,"No");

    
    return answer;
}