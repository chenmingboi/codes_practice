#include<bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long asuan(int n, int m) {
    long long  ans = n;
    for(int i = 1;i < m;i++) {
        ans *= (n-i);
        ans %= MOD;
    }
    // for(int i = 2;i <= m;i++) {
    //     ans /= i;
    // }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, maxNum = 0;
    cin >> n;
    vector<int>m(1005, 0);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        maxNum = max(maxNum, num);
        m[num]++;
    }
    long long ans = 1;
    int sum = 0;
    for(int i = 1;i <= maxNum;i++) {
        if(m[i] == 0) continue;
        if(m[i] > i-sum) {
            cout << 0; return 0;
        }
        ans *= asuan(i - sum, m[i]);
        sum += m[i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}