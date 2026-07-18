def solution(s):
    
    answer = []
    count = 0
    rm_zero = 0
    
    while True:
        
        before_len = len(s)
        
        s = s.replace("0","")
        
        after_len = len(s)
        
        s = bin(len(s))[2:]
        
        rm_zero += before_len - after_len
        
        count += 1
        
        if s == '1':
            break
    
    return count, rm_zero