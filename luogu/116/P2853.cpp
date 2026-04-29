#include<bits/stdc++.h>
using namespace std;

//看的题解的思路，从每个奶牛的位置进行dfs，到达牧场就对该牧场计数加一
//最后有几个计数为k的牧场，就是最后的答案
vector<int>craw;
vector<vector<int>>edges;
vector<int>cnt;

//注意这里要防止环的出现，题目中没有说没有环，如果不加判断的话，会导致无效递归MLE
void dfs(int u, vector<bool>& visit) {
    visit[u] = true;
    cnt[u]++;
    for(auto v : edges[u]) {
        if(!visit[v]) {
            dfs(v, visit);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n, m;
    cin >> k >> n >> m;
    craw.resize(k+1), edges.resize(n+1), cnt.resize(n+1, 0);
    for(int i = 1;i <= k;i++) {
        cin >> craw[i];
    }
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    for(int i = 1;i <= k;i++) {
        vector<bool>visit(n+1,false);
        dfs(craw[i], visit);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(cnt[i] == k) ans++;
    }
    cout << ans;
    return 0;
}