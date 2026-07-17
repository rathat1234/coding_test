def solution(n):
    num1 = n ** 0.5
    test =  num1 % 1

    if num1 > 0 and test == 0:
        answer  = (num1+1) ** 2
    else:
        answer = -1
        

    return answer