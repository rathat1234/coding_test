def solution(n):
    answer = 0
    
    answer += n//100000000
    n = n%100000000
    
    answer += n//10000000
    n = n%10000000

    
    answer += n//1000000
    n = n%1000000

    
    answer += n//100000
    n = n%100000

    
    answer += n//10000
    n = n%10000

    
    answer += n//1000
    n = n%1000

    
    answer += n//100
    n = n%100

    
    answer += n//10
    n = n%10

    answer += n//1
    n = n%1

    
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer