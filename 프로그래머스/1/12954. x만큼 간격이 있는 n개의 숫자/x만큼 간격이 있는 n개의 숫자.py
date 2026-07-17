def solution(x, n):
    answer = []
    n1 = x*n
    
    if(n1>=0):
        n1 += 1
    else:
        n1 -= 1
    if x != 0:
        for i in range(x,n1,x):
            answer.append(i)
    else:
        for i in range(n):
            answer.append(0)
    return answer