def solution(s):
    a = s.split(" ")
    
    for i in range(len(a)):
        if a[i]:
            a[i] = a[i][0:1].upper() + a[i][1:].lower()
    
    a = " ".join(a)
    return a