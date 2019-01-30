#include <iostream>
#include <cmath>
using namespace std;
constexpr int N = 1024;
constexpr double eps = 1e-6;
double con1[N], con2[N];
double ans[N << 1];
void input(double*  arr) {
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int e; double c;
        scanf("%d %lf", &e, &c);
        arr[e] = c;
    }
}

void product() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            double c = con1[i] * con2[j];
            ans[i + j] +=c;
        }
    }
}

void output() {
    int cnt = 0;
    for(int i = 0; i < N * 2; ++i) {
        if(fabs(ans[i]) > eps) {
            ++cnt;
        }
    }
    printf("%d", cnt);
    for(int i = N * 2 - 1; i >= 0; --i) {
        double c = ans[i];
        if(fabs(c) > eps) {
            printf(" %d %.1f", i, c);
        }
    }
    puts("");
}

int main() {
    input(con1);
    input(con2);
    product();
    output();
    return 0;
}
