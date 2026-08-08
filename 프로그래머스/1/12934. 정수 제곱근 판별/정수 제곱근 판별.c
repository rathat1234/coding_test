#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long answer = 0;
    long long temp = sqrt(n);
    if(n == temp*temp)
    {
        temp += 1;
        answer = temp*temp;
    }
    else
    {
        answer = -1;    
    }
    return answer;
}