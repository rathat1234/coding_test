def solution(arr):
    answer = []
    cnt = 0
    if arr != []:
        for i in range(len(arr)-1):
            if i == 0:
                answer.append(arr[i])
                
            if arr[i] != arr[i+1]:
                    answer.append(arr[i+1])
    elif len(arr) == 1 or len(arr) == 0: 
        answer = arr
                    
                
    return answer