#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

inline int ConvertC(char c) { return (c >= '0' && c <= '9') ? (c - '0') : (c - 'a' + 10); }
inline char ConvertN(int n) { const char table[] = "0123456789abcdefghijklmnopqrstuvwxyz"; return table[n]; }

ll toNum(const string& num, ll radix, ll t) {
    __int128 res = 0;
    for(auto c : num) {
        res = res * radix + ConvertC(c);
        if(res > t) return t + 1;
    }
    return (ll)res;
}

/* string toString(ll num, int radix) { */
/*     if(num == 0) return "0"; */
/*     string result; */
/*     while(num) { */
/*         result += ConvertN(num % radix); */
/*         num /= radix; */
/*     } */
/*     reverse(result.begin(), result.end()); */
/*     return result; */
/* } */

int main() {
    string l, r;
    int id, radix;
    cin >> l >> r >> id >> radix;
    if(id == 2) swap(l, r);
    ll num = toNum(l, radix, 1e15);
    int res = -1;
    ll min_b = -1, max_b = 1e18;
    for(auto c : r) min_b = max((ll)ConvertC(c) + 1, min_b);

    while(min_b <= max_b) {
        ll mid = (min_b + max_b) / 2;
        ll now = toNum(r, mid, num);
        if(now >= num) {
            max_b = mid - 1;
            if(now == num) res = mid;
        } else {
            min_b = mid + 1;
        }
    }
    if(res == -1) puts("Impossible");
    else printf("%d\n", res);
    return 0;
}
