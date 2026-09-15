#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
long long solution(int n) {
    long long gap = 1,  gap2 = 2, temp = 0;
    
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    
    for(int i = 3; i <= n ; i++)
    {
        temp = (gap + gap2)%1234567;
        gap = gap2;
        gap2 = temp;
    }

    
    return gap2;
}





/*
1 : 1                                                                                                       1 
2 : 1 1 /2                                                                                                  2 1
3 : 1 1 1 / 2 1 / 1 2                                                                                       3 1
4 : 1 1 1 1 / 2 1 1 / 1 2 1 / 1 1 2 / 2 2                                                                   5 2
5 : 1 1 1 1 1 / 2 1 1 1 / 1 2 1 1 / 1 1 2 1 / 1 1 1 2 / 2 2 1 / 2 1 2 / 1 2 2                               8 3
6 : 111111 / 21111 / 12111 / 11211 / 11121 / 11112 / 2211 / 2121 / 2112/ 1221 / 1212 / 1122 / 222          13 5
*/