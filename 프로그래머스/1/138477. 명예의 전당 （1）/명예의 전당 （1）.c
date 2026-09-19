#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int* solution(int k, int score[], size_t score_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    // k 는 점수 목록 len / score 는 매일 발표되는 점수 / score_len 은 점수의 갯수
    int* answer = malloc(sizeof(int)*score_len);

    int* rank = malloc(sizeof(int)*k);
    
    memset(answer,-1,sizeof(int)*score_len);
    memset(rank,-1,sizeof(int)*k);
    
    for(int i = 0 ; i < score_len ; i++)
    {
        int temp = -1;
        for(int j = 0 ; j < k ; j++)
        {
            if(rank[j]==-1)
            {
                rank[j]=score[i];
                temp = score[i];
                break;
            }
            else if(rank[j]<score[i])
            {
                temp = rank[j];
                rank[j]=score[i];
                score[i]=temp;
            }
            
            if(j==k-1)
            {
                temp = rank[j];
            }
        }
        answer[i]=temp;
    }
    
    
    
    
    return answer;
}