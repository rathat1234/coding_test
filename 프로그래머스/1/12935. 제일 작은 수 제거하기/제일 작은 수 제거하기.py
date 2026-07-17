def solution(arr):
    min_index = 0
    if len(arr)==1:
        arr = [-1]
    else:
        for i in range(len(arr)):
            if arr[min_index]>arr[i]:
                min_index = i
        arr.pop(min_index)
    
    return arr