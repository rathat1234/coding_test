def solution(arr1, arr2):
    row, col = len(arr1), len(arr1[0])
    answer = []
    
    for i in range(row):
        answer.append([])
        for j in range(col):
            answer[i].append(arr1[i][j]+arr2[i][j])
    
    return answer