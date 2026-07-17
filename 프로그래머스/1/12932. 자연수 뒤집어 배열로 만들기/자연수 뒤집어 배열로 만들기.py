def solution(n):
    answer = []
    num1 = 10000000000
    
    for i in range(11):
        
        insert_num = n // num1
        
        if insert_num != 0 or answer != []:
            answer.insert(0,insert_num)
        
        n -= num1*insert_num
        num1 /= 10
        
        
    return answer