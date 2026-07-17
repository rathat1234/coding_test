def solution(n):
    answer = 0
    arr = []
    num1 = 1000000000
    
    for i in range(10):
        num2 = n // num1
        
        if arr != [] or num2 != 0:
            arr.append(num2)
        
        n -= num1*num2
        num1 /= 10
    
    num1 = 1
    for i in range(len(arr)-1):   
        num1 *= 10
    
    for i in range(len(arr)):
        for j in range(i+1):
            if arr[i]>arr[j]:
                temp   = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
                
    arr.reverse()
    
    for i in range(len(arr)):
        answer += arr[len(arr)-1-i]*num1
        num1 /= 10
        
        
    return answer
