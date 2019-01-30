#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
    char ID[20];
    int sh, sm, ss;
    int eh, em, es;
};

int main() {
    vector<Record> rv;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        Record tmp;
        scanf("%s %d:%d:%d %d:%d:%d", tmp.ID, &tmp.sh, &tmp.sm, &tmp.ss,
                &tmp.eh, &tmp.em, &tmp.es);
        rv.push_back(tmp);
    }
    auto fi = min_element(rv.begin(), rv.end(), [](const Record& l, const Record& r) {
                if(l.sh != r.sh) return l.sh < r.sh;
                if(l.sm != r.sm) return l.sm < r.sm;
                if(l.ss != r.ss) return l.ss < r.ss;
                return false;
            });
    auto se = max_element(rv.begin(), rv.end(), [](const Record& l, const Record& r) {
                if(l.eh != r.eh) return l.eh < r.eh;
                if(l.em != r.em) return l.em < r.em;
                if(l.es != r.es) return l.es < r.es;
                return false;
            });

    printf("%s %s\n", fi->ID, se->ID);
    return 0;
}
