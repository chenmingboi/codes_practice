#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>dfn, low, belong;
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
    if(dfn[u] == low[u]) {
        scc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            instack[v] = 0;
            belong[v] = scc_cnt;
        } while(u != v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1);
    belong.resize(n+1), instack.resize(n+1, 0);
    for(int i = 1;i <= n;i++) {
        int num;
        while(cin >> num) {
            if(num != 0) {
                edges[i].push_back(num);
            } else {
                break;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    vector<int>indeg(scc_cnt+1), outdeg(scc_cnt+1);
    for(int u = 1;u <= n;u++) {
        for(auto v : edges[u]) {
            if(belong[u] != belong[v]) {
                indeg[belong[v]]++;
                outdeg[belong[u]]++;
            }
        }
    }
    int num_in = 0, num_out = 0;
    for(int i = 1;i <= scc_cnt;i++) {
        if(indeg[i] == 0) num_in++;
        if(outdeg[i] == 0) num_out++;
    }
    int ans2 = max(num_in, num_out);
    if(scc_cnt == 1) ans2 = 0;
    //第一个解就是入度为0的点的数量,第二个解为max(入度为0的节点数量，出度为0的节点数量)
    cout << num_in << endl << ans2;
    return 0;
}