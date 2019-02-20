#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int N = 50;

int post[N], in[N];

vector<int> node[N];

void solve(int pl, int pr, int il, int ir, int l) {
    if(pl > pr) return;
    /* printf("%d %d %d %d\n", pl, pr, il, ir); */
    /* getchar(); */
    
    int prt = post[pr];
    int irt = find(in + il, in + ir + 1, prt) - in;

    node[l].push_back(prt);

    int lc = irt - il, rc = ir - irt;
    solve(pl, pl + lc - 1, il, irt - 1, l + 1);
    solve(pl + lc, pr - 1, irt + 1, ir, l + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", post + i);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", in + i);
    }
    solve(0, n - 1, 0, n - 1, 0);
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(auto x : node[i]) {
            ++cnt;
            printf("%d%c", x, " \n"[cnt == n]);
        }
    }
    return 0;
}
