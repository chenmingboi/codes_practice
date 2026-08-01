#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>dfn, low, belong, cnt;
vector<char>instack;
stack<int>st;
int tot = 0, scc_cnt = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    instack[u] = 1;
    for(auto v : edges[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        scc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            instack[v] = 0;
            belong[v] = scc_cnt;
            cnt[scc_cnt]++;
        } while(u != v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    //求唯一的一个没有出度的节点对应原图中的强连通分量中的节点个数（构造的有向无环图）
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1);
    belong.resize(n+1), cnt.resize(n+1), instack.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    vector<int>outdeg(scc_cnt+1);
    for(int u = 1;u <= n;u++) {
        for(auto v : edges[u]) {
            if(belong[u] != belong[v]) {
                outdeg[belong[u]]++;
            }
        }
    }
    int cntout = 0, ans = 0;
    for(int i = 1;i <= scc_cnt;i++) {
        if(outdeg[i] == 0) {
            cntout++;
            ans = cnt[i];
        }
        if(cntout > 1) {
            ans = 0;
            break;
        }
    }
    cout << ans;
    return 0;
}