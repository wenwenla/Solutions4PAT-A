#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
constexpr int N = 1024;
struct Ufs {
    int fa[N];
    void init() { memset(fa, 0xff, sizeof(fa)); }
    int find(int x) {
        int p = x;
        while(fa[p] > 0) p = fa[p];
        while(x != p) { int tmp = fa[x]; fa[x] = p; x = tmp; }
        return p;
    }
    void join(int u, int v) {
        int uf = find(u), vf = find(v);
        if(uf == vf) return;
        if(-fa[uf] > -fa[vf]) {
            fa[uf] += fa[vf];
            fa[vf] = uf;
        } else {
            fa[vf] += fa[uf];
            fa[uf] = vf;
        }
    }
} ufs;

struct edge {
    int u, v;
};

int main() {
    int n, m, k;
    vector<edge> eg;
    scanf("%d %d %d", &n, &m, &k);
    while(m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        eg.push_back({u, v});
    }
    while(k--) {
        ufs.init();
        int x;
        scanf("%d", &x);
        for(auto e : eg) {
            if(e.u != x && e.v != x) ufs.join(e.u, e.v);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(ufs.fa[i] < 0) {
                ++cnt;
            }
        }
        printf("%d\n", cnt - 2);
    }
    return 0;
}
