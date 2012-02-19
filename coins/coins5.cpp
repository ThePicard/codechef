#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long int uint64;

map<uint64, uint64> cache;

uint64 maxbucks(uint64 coin) {
    uint64 a, b, c, abc;
    map<uint64,uint64>::iterator it;

    it = cache.find(coin);
    if (it != cache.end())
        return it->second;

    a = coin / 2;
    b = coin / 3;
    c = coin / 4;
    if (a > 11) {
        a = maxbucks(a);
        if (b > 11) {
            b = maxbucks(b);
            if (c > 11) {
                c = maxbucks(c);
            }
        }
    }
    abc = a + b + c;
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
