#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
using PII = pair<int, int>;
constexpr int V = 505, E = V * V;

struct Edge {
    int to, next, cost;
} edge[E];
int head[V], cnt[V], tot, n, m, s, t;

void init() {
    memset(head, 0xff, sizeof(head));
    tot = 0;
}

void addedge(int u, int v, int c) {
    edge[tot] = {v, head[u], c};
    head[u] = tot++;
}

void input() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 0; i < n; ++i) {
        scanf("%d", cnt + i);
    }
    int u, v, c;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        addedge(u, v, c);
        addedge(v, u, c);
    }
}

int dist[V], dcnt[V], team[V];

void solve() {
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, s});
    memset(dist, 0x3f, sizeof(dist));
    memset(team, 0, sizeof(team));
    memset(dcnt, 0, sizeof(dcnt));
    dist[s] = 0; dcnt[s] = 1; team[s] = cnt[s];
    while(!pq.empty()) {
        PII now = pq.top();
        pq.pop();
        for(int i = head[now.second]; i != -1; i = edge[i].next) {
            if(dist[edge[i].to] > now.first + edge[i].cost) {
                dist[edge[i].to] = now.first + edge[i].cost;
                dcnt[edge[i].to] = dcnt[now.second];
                team[edge[i].to] = team[now.second] + cnt[edge[i].to];
                pq.push({dist[edge[i].to], edge[i].to});
            } else if(dist[edge[i].to] == now.first + edge[i].cost) {
                dcnt[edge[i].to] += dcnt[now.second];
                team[edge[i].to] = max(team[edge[i].to], team[now.second] + cnt[edge[i].to]);
            }
        }
    }
    printf("%d %d\n", dcnt[t], team[t]);
}

int main() {
    init();
    input();
    solve();
    return 0;
}
