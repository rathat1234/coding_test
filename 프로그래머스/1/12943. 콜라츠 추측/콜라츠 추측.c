#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(long long num) {
    int answer = 0;
    
    if (num==0) 
            answer = -1;
    
    while(true){
        if (answer >= 500)
        {
            answer = -1;
            break;
        }
        else if (num==1)
            break;
        
        if(num%2==0)
        {
            num = num/2;
        }
        else
        {
            num = (num * 3) + 1;
        }
        answer++;
    }
    return answer;
}