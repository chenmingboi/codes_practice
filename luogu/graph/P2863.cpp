#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges, belong;
vector<int>dfn, low;
//0代表不在栈中，1代表在栈中
vector<char>inStack;
stack<int>st;
int tot = 0, scc_cnt = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    inStack[u] = true;
    for(auto v : edges[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        scc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            inStack[v] = 0;
            belong[scc_cnt].emplace_back(v);
        } while(u != v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), belong.resize(n+1);
    dfn.resize(n+1), low.resize(n+1);
    inStack.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        edges[a].emplace_back(b);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    int ans = 0;
    for(int i = 1;i <= scc_cnt;i++) {
        if(belong[i].size() > 1) ans++;
    }
    cout << ans;
    return 0;
}