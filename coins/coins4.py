import sys

cache = {}

def maxbucks(coin):
    if coin in cache:
        return cache[coin]
    a = coin // 2
    b = coin // 3
    c = coin // 4
    if a > 11:
        a = maxbucks(a)
        if b > 11:
            b = maxbucks(b)
            if c > 11:
                c = maxbucks(c)
    abc = a + b + c
    if abc < coin:
        abc = coin
    cache[coin] = abc
    return abc

lines = sys.stdin.readlines()
for l in lines:
    print(maxbucks(int(l)))
