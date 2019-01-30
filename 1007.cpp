#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n;
    vector<int> iv;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        iv.push_back(x);
    }
    ll s = 0, ans = -1;
    int end = n - 1, start = 0, np = 0;
    for(int i = 0; i < n; ++i) {
        s += iv[i];
        if(s > ans) {
            ans = s;
            start = np;
            end = i;
        }
        if(s < 0) {
            s = 0;
            np = i + 1;
        }
    }
    if(ans < 0) {
        ans = 0;
        start = 0;
        end = n - 1;
    }
    printf("%lld %d %d\n", ans, iv[start], iv[end]);
    return 0;
}
