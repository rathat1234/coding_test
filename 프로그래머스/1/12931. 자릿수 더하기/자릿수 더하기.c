#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int mul = 100000000;
    while(n!=0)
    {
        answer += n/mul;
        n -= mul*(n/mul);
        mul /= 10;
    }
    
    return answer;
}