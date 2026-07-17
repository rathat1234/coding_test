def solution(numbers):
    answer = 45
    sum = 0
    for i in range(len(numbers)):
        sum += numbers[i]
    answer -= sum
    return answer