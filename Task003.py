
def un_kp(price, lenge, max_len, rope, t):
    if(rope==0 and max_len==0):
        return 0

    elif(lenge[rope-1] <= max_len):
        t[rope][max_len] = max(price[rope - 1]+ un_kp(price, lenge,max_len - lenge[rope - 1], rope),un_kp(price, lenge, max_len, rope - 1))

    else:
        t[rope][max_len] = un_kp(price, lenge, max_len, rope - 1)

    return t[rope][max_len]

def main():
    price = []
    i = 0
    rope = int(input())
    for i in range(rope):
        price = map(int,input().split())
    lenge = []
    for i in range(lenge):
        lenge[i] = i+1
        i += 1
    max_len = rope
    t = [rope][rope]
    print(un_kp)