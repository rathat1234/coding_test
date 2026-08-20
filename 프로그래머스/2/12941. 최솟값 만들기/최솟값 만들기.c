#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.

int compare_asc(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}
int compare_desc(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y) return -1;
    if (x < y) return 1;
    return 0;
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    int temp = 0;
    qsort(A,A_len,sizeof(int),compare_asc);
    qsort(B,B_len,sizeof(int),compare_desc);
    
    
    for (int i = 0 ; i < A_len ; i++)
    {
        answer += A[i]*B[i];
    }
    
    
    return answer;
}

