#include<bits/stdc++.h>
using namespace std;

long long ans = 0;
int n, k;

void dfs(int sum, int start, int len) {
    if(len == k) {
        if(sum == n) ans++;
        return;
    } else if(len > k) {
        return;
    }
    for(int i = start;i <= n-sum;i++) {
        sum += i;
        dfs(sum, i, len+1);
        sum -= i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    dfs(0, 1, 0);
    cout << ans;
    return 0;
}