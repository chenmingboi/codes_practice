#include<bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>edges(n+1);
    vector<int>weight(n+1);
    for(int i = 0;i < n-1;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) cin >> weight[i];
    long long lianhemax = 0, lianhesum = 0;
    //利用数学公式(a+b+c)^2 = a*a + b*b + c*c + 2ab + 2ac + 2bc
    for(int i = 1;i <= n;i++) {
        if(edges[i].size() < 2) continue;
        long long squaresum = 0LL, sum = 0LL;
        int max1 = 0, max2 = 0;
        for(auto v : edges[i]) {
            sum += weight[v];
            squaresum += (1LL * weight[v] * weight[v]) % MOD;
            if(weight[v] >= max1) {
                max2 = max1;
                max1 = weight[v];
            } else if(weight[v] > max2) {
                max2 = weight[v];
            }
        }
        lianhemax = max(lianhemax, 1LL * max1 * max2);
        lianhesum += (sum * sum - squaresum) % MOD;
        lianhesum %= MOD;
    }
    cout << lianhemax << ' ' << lianhesum;
    return 0;
}