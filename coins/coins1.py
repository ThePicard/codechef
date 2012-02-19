import sys

cache = {}

def maxbucks(coin):
    if coin in cache:
        return cache[coin]
    a = coin // 2
    b = coin // 3
    c = coin // 4
    if a+b+c < 12:
        return coin
    abc = maxbucks(a) + maxbucks(c) + maxbucks(b)    
    if abc < coin:
        abc = coin
    cache[coin] = abc
    return abc

lines = sys.stdin.readlines()
for l in lines:
    print(maxbucks(int(l)))
