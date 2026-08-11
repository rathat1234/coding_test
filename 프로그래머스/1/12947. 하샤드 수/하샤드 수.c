#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    int temp = 0, temp2 = 0, mul = 10000, num = x;
    for(int i = 0 ; i < 5;i++)
    {
        temp = num / mul;
        num -= temp*mul;
        mul /= 10;
        temp2 += temp;
    }
    if ( x == 0)
        return false;
    if ( 0 == (x % temp2))
        return true;
    else
        return false;
}