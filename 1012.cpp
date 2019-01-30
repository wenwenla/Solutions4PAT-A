#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
using Grades = tuple<int, int, int>;

map<int, Grades> in;
int n, m;
vector<int> C, M, E, A;

void input() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        int id, a, b, c;
        scanf("%d", &id);
        scanf("%d %d %d", &a, &b, &c);
        in[id] = {a, b, c};
        C.push_back(a);
        M.push_back(b);
        E.push_back(c);
        A.push_back(a + b + c);
    }
    sort(C.begin(), C.end(), greater<int>());
    sort(M.begin(), M.end(), greater<int>());
    sort(E.begin(), E.end(), greater<int>());
    sort(A.begin(), A.end(), greater<int>());
}

void solve(Grades x) {
    int c = get<0>(x), m = get<1>(x), e = get<2>(x);
    int a = c + m + e;
    int crk = lower_bound(C.begin(), C.end(), c, greater<int>()) - C.begin() + 1;
    int mrk = lower_bound(M.begin(), M.end(), m, greater<int>()) - M.begin() + 1;
    int erk = lower_bound(E.begin(), E.end(), e, greater<int>()) - E.begin() + 1;
    int ark = lower_bound(A.begin(), A.end(), a, greater<int>()) - A.begin() + 1;
    vector<int> tmp{crk, mrk, erk, ark};
    int mx = *min_element(tmp.begin(), tmp.end());
    char bst;
    if(ark == mx) {
        bst = 'A';
    } else if(crk == mx) {
        bst = 'C';
    } else if(mrk == mx) {
        bst = 'M';
    } else {
        bst = 'E';
    }
    printf("%d %c\n", mx, bst);
}

void solve() {
    while(m--) {
        int id;
        scanf("%d", &id);
        auto it = in.find(id);
        if(it == in.end()) {
            puts("N/A");
        } else {
            solve(it->second);
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}
