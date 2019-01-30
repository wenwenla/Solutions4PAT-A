#include <iostream>
#include <cstring>
using namespace std;
constexpr int V = 128, E = 128;

struct Edge {
    int to, next;
} eg[E];
int head[V], tot, count[V], mx;

void init() {
    memset(head, 0xff, sizeof(head));
    memset(count, 0, sizeof(count));
    tot = 0;
    mx = 0;
}

void addedge(int f, int t) {
    eg[tot] = {t, head[f]};
    head[f] = tot++;
}


void dfs(int rt, int level) {
    mx = max(mx, level);
    bool isLeaf = true;
    for(int i = head[rt]; i != -1; i = eg[i].next) {
        isLeaf = false;
        dfs(eg[i].to, level + 1);
    }
    if(isLeaf) ++count[level];
}

void input() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int rt, k, x;
        scanf("%d %d", &rt, &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d", &x);
            addedge(rt, x);
        }
    }
}

void output() {
    for(int i = 0; i <= mx; ++i) {
        printf("%d%c", count[i], " \n"[i == mx]);
    }
}

int main() {
    init();
    input();
    dfs(1, 0);
    output();
    return 0;
}
