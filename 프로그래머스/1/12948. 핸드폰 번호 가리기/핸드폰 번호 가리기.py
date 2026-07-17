def solution(phone_number):
    arr = list(phone_number)
    for i in range(len(phone_number)-4):
        arr[i] = '*'
    phone_number = "".join(arr)
    return phone_number