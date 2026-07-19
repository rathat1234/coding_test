def solution(n, m):
    n_divisor = []
    m_divisor = []
    
    common_divisor = 0
    common_multiple = 1
    
    for i in range(1,n+1):
        if n % i == 0:
            n_divisor.append(i)
            
    for i in range(1,m+1):
        if m % i == 0:
            m_divisor.append(i)
    
    for i in range(len(n_divisor)):
        if n_divisor[i] in m_divisor:
            common_divisor = n_divisor[i]
    
    common_multiple = n * m // common_divisor
    
    
    
    return common_divisor, common_multiple