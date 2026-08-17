#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    long long tot_price = 0;
    for(int i = 1 ; i <= count ; i++)
    {
        tot_price += price*i;
    }
    answer = money-tot_price;
    if(answer < 0)
    {
        answer *= -1;
    }
    else
    {
        answer = 0;
    }
    return answer;
}