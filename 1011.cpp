#include <iostream>
#include <vector>
using namespace std;

int main() {
    double ans = 1.0;
    for(int i = 0; i < 3; ++i) {
        double mx = -1, x;
        int id;
        for(int j = 0; j < 3; ++j) {
            scanf("%lf", &x);
            if(x > mx) {
                mx = x;
                id = j;
            }
        }
        ans *= mx;
        printf("%c ", "WTL"[id]);
    }
    printf("%.2f\n", 2 * (ans * .65 - 1));
    return 0;
}
