def solution(s):
    arr = list(s)
    s = ""
    for j in range(len(arr)-1,0,-1):
        for i in range(j):
            if arr[i] < arr[i+1]:
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp
    
    for i in range(len(arr)):
        s += arr[i]
        
    return s