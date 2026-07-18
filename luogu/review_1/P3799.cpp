#include<bits/stdc++.h>
using namespace std;

const long long Mod = 1e9+7;

bool comp(const int& a, const int& b) {
    return a > b;
}

long long cab(const int& a, const int& b) {
    long long result = 1LL;
    for(int i = 0;i < b;i++) {
        result *= (a-i) * 1LL;
    }
    for(int i = 1;i <= b;i++) {
        result /= (i * 1LL);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(5002, 0);
    for(int i = 0;i < n;i++) {
        int len = 0;
        cin >> len;
        a[len]++;
    }
    long long result = 0LL;
    for(int i = 5000;i >= 1;i--) {
        if(a[i] >= 2) {
            long long temp = 0LL;
            //这里的循环条件要注意，第一次写为j <i/2会导致当i=奇数比如5
            //的时候 i/2 =2,但是此时是j<i/2所以不会遍历2所以会导致缺少
            //2 3这种组合
            for(int j = 1;j < i-j;j++) {
                if(a[j] != 0 && a[i-j] != 0) temp += a[j] * a[i-j] * 1LL;
            }
            if(i % 2 == 0 && a[i/2]) temp += cab(a[i/2], 2);
            result += temp * cab(a[i], 2);
            result %= Mod;
        }
    }
    cout << result;
    return 0;
}