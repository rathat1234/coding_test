def solution(s):
    answer = False
    arr = list(s)
    p_letter = 0
    y_letter = 0
    for i in range(len(arr)):
        if arr[i]=='p':
            p_letter += 1
        elif arr[i]=='P':
            p_letter += 1
        if arr[i]=='y':
            y_letter += 1
        elif arr[i]=='Y':
            y_letter += 1
            
    if p_letter == y_letter:
        answer = True

    return answer