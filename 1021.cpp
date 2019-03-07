#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

constexpr int V = 10004;

struct edge {
    int to, nxt;
} eg[V << 1];
int head[V], tot, h[V];

void init() {
    memset(head, 0xff, sizeof(head));
    memset(h, 0xff, sizeof(h));
    tot = 0;
}

void addedge(int from, int to) {
    eg[tot] = {to, head[from]};
    head[from] = tot++;
}

void dfs(int rt) {
    h[rt] = 0;
    for(int i = head[rt]; i != -1; i = eg[i].nxt) {
        if(h[eg[i].to] == -1) {
            dfs(eg[i].to);
            h[rt] = max(h[rt], h[eg[i].to] + 1);
        }
    }
}


int main() {
    int n;
    init();
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(h[i] < 0) {
            dfs(i);
            ++cnt;
        }
    }
    
    if(cnt == 1) {
        //Here is a brute force solution
        vector<int> mh;
        mh.push_back(h[1]);
        for(int i = 2; i <= n; ++i) {
            memset(h, 0xff, sizeof(h));
            dfs(i);
            mh.push_back(h[i]);
        }

        int mx = *max_element(mh.begin(), mh.end());

        for(int i = 1; i <= n; ++i) {
            if(mh[i - 1] == mx) printf("%d\n", i);
        }
    } else {
        printf("Error: %d components\n", cnt);
    }
    return 0;
}
