def solution(price, money, count):
    temp = 0
    for i in range(1,count+1):
        temp += price*i
    if money > temp:
        answer = 0
    else:
        answer = (money - temp) * -1
    return answer