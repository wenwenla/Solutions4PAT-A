#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string table[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void solve(const string& n) {
    int s = 0;
    for(auto i : n) {
        s += i - '0';
    }
    vector<string> res;
    if(s == 0) res.push_back(table[0]);
    while(s) {
        res.push_back(table[s % 10]);
        s /= 10;
    }
    reverse(res.begin(), res.end());
    int sz = res.size();
    for(int i = 0; i < sz; ++i) printf("%s%c", res[i].c_str(), " \n"[i == sz - 1]);
}

int main() {
    char n[128];
    scanf("%s", n);
    solve(n);
    return 0;
}
