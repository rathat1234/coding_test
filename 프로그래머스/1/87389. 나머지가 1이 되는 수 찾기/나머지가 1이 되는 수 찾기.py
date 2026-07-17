def solution(n):
    answer = 0
    for i in range(1,n+1):
        num1=n%i
        if num1==1:
            answer = i
            break
    return answer