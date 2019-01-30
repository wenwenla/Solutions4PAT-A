#include <iostream>
#include <cmath>
using namespace std;
constexpr int N = 1024;
constexpr double eps = 1e-6;
double con1[N], con2[N];

void input(double* arr) {
    int k, e;
    double c;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d %lf", &e, &c);
        arr[e] = c;
    }
}

void output() {
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        if(fabs(con1[i] + con2[i]) > eps) {
            ++cnt;
        }
    }
    printf("%d", cnt);
    for(int i = N - 1; i >= 0; --i) {
        double c = con1[i] + con2[i];
        if(fabs(c) > eps) {
            printf(" %d %.1f", i, c);
        }
    }
    puts("");
}

int main() {
    input(con1);
    input(con2);
    output();
    return 0;
}
