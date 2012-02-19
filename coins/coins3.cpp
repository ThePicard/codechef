#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long int uint64;

map<uint64, uint64> cache;

uint64 maxbucks(uint64 coin) {
    map<uint64,uint64>::iterator it;
    it = cache.find(coin);
    if (it != cache.end())
        return it->second;
    uint64 a, b, c, abc;
    a = coin / 2;
    b = coin / 3;
    c = coin / 4;
    if ((a + b + c) < 12)
        return coin;
    abc = maxbucks(a) + maxbucks(b) + maxbucks(c);
    if (abc < coin)
        abc = coin;
    cache[coin] = abc;
    return abc;
}

int main() {
    int read;
    while(1) {
        cin >> read;
        if (cin.eof()) return 0;
        cout << maxbucks(read) << endl;
    }
}
