#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int memo[100001];

int F(int n){
    if(n <= 0)
        return 0;
    else if(n == 1 || n==2)
        return 1;
    if(memo[n] != 0)
        return memo[n];

    return memo[n] = (F(n-1) + F(n-2)) % 1234567;
}

int solution(int n) {
    return F(n);
}