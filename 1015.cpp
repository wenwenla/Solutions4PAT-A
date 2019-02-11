#include <iostream>
using namespace std;

bool isprime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= (n + i - 1) / i; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int rev(int n, int d) {
    string res;
    if(n == 0) res += '0';
    while(n) {
        res += char(n % d + '0');
        n /= d;
    }
    int r = 0;
    for(auto c : res) {
        r = r * d + c - '0';
    }
    return r;
}

int main() {
    int n, d;
    while(cin >> n) {
        if(n < 0) break;
        cin >> d;
        if(isprime(n) && isprime(rev(n, d))) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
