#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
int solution(int n) {
    int answer = 0;
    long long temp = 0;
    long long num = 3;
    long long val = 10;
    long long t = n%num;
    temp = t;
    n -= temp;
    while(n != 0)
    {
        t = (n / num) % 3;
        temp += t * val;
        n -= t * num;
        num *= 3;
        val *= 10;
    }
    
    while(temp != 0) 
    { 
        t = temp % 10; 
        answer = answer * 3 + t; 
        temp /= 10; 
    }
    return answer;
}