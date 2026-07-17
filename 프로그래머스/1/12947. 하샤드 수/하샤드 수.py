def solution(x):
    arr = list(str(x))
    num1 = 0
    
    for i in range(len(arr)):
        num1 += int(arr[i])
    
    if x % num1 == 0:
        answer = True
    else:
        answer = False
        
    
    
    return answer