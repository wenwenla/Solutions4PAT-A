#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1024, INF = 1e9+7;
int cost[N], finished[N], p = 0;
int last[N];
int n, m, k, q;

queue<int> Q[20];

int findQue() {
    int ret = -1, st = m;
    for(int i = 0; i < n; ++i) {
        if(Q[i].size() < st) {
            ret = i;
            st = Q[i].size();
        }
    }
    return ret;
}

int nextTime() {
    int mn = INF;
    for(int i = 0; i < n; ++i) {
        if(!Q[i].empty()) mn = min(mn, cost[Q[i].front()] + last[i]);
    }
    for(int i = 0; i < n; ++i) {
        if(!Q[i].empty() && cost[Q[i].front()] + last[i] == mn) {
            finished[Q[i].front()] = mn;
            Q[i].pop();
            last[i] = mn;
        }
    }
    return mn;
}

void show(int pid) {
    int e = 60 * (17 - 8);
    if(finished[pid] - cost[pid] >= e) {
        puts("Sorry");
        return;
    }
    int t = finished[pid];
    int h = t / 60 + 8, m = t % 60;
    printf("%02d:%02d\n", h, m);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 0; i < k; ++i) {
        scanf("%d", cost + i);
    }
    int nowp = 0;
    while(true) {
        int qid;
        while(nowp < k && (qid = findQue()) != -1) {
            Q[qid].push(nowp);
            ++nowp;
        }
        if(nextTime() == INF) break;
    }
    while(q--) {
        int x;
        scanf("%d", &x);
        show(x - 1);
    }
    return 0;   
}
