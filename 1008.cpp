#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int pre = 0, ans = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(x > pre) {
            ans += (x - pre) * 6 + 5;    
        } else {
            ans += (pre - x) * 4 + 5;
        }
        pre = x;
    }
    printf("%d\n", ans);
    return 0;
}
