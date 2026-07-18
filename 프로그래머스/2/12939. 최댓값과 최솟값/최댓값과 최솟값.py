def solution(s):
    arr = s.split(" ")
    max, min = int(arr[0]), int(arr[0])
    for i in range(len(arr)):
        temp = int(arr[i])
        if max < temp:
            max = temp
        elif min > temp:
            min = temp
    
    return f"{min} {max}"