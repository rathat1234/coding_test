#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    long long mul = 10000000000;
    int temp = 0;
    int* answer = (int*)malloc(sizeof(int)*11);
    for(int i = 10; i >=0 ; i--){
        answer[i] = n / mul;
        n -= answer[i] *mul;
        mul /= 10;
    }
    return answer;
}