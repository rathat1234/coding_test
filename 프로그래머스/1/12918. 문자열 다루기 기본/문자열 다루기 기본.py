def solution(s):
    
    answer = False
    is_size = False
    is_type = False
    
    if len(s) == 4 or len(s) == 6:
        is_size = True

    if s.isdigit():
        is_type = True
    
    if is_type and is_size:
        answer = True
    
    return answer