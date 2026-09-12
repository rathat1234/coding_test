#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    int answer = 0; // n 빈병 / 갯수 a 콜라를 지급하는 빈병 수 / b 지급하는 콜라 수
    int num = 0, temp = 0;
    while(n >= a)
    {
        num = n / a;
        
        answer += num * b;
        
        n = (num * b) + (n % a);
    }     
        
    return answer;
}

/*
        if(n < a)
        {
            if((n + temp) / a != 0)
            {
                n = ((n + temp) / a )* b;
                answer += n;
                temp = 0;
                continue;
            }
            break;        
        }
            
        
        num = n / a;
        
        if(num!=0)
        {
            temp += n%a;
            n = num*b;
            answer += n;
            continue;
        }
        */