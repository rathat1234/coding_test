def solution(arr, divisor):
    answer = []
    for i in range(len(arr)):
        if arr[i]%divisor==0:
            answer.append(arr[i])
        if answer == [] and i == len(arr)-1:
            answer.append(-1)
            
    answer.sort()
    return answer