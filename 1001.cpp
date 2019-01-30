#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string format(int number) {
    bool neg = number < 0;
    if (neg) number = -number;
    string res;
    if (number == 0) res = "0";
    else {
        int cnt = 0;
        while(number) {
            res += char(number % 10 + '0');
            number /= 10;
            ++cnt;
            if(cnt % 3 == 0 && number != 0) res += ',';
        }
        reverse(res.begin(), res.end());
    }
    if (neg) res = "-" + res;
    return res;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s\n", format(a + b).c_str());
    return 0;
}
