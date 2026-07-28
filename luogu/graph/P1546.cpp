#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u;
    int v;
    int w;
};

bool comp(const edge& a, const edge& b) {
    return a.w < b.w;
}

vector<edge>edges;
vector<int>fa;
vector<int>weight;

int n;

int findFa(int x) {
    if(x == fa[x]) return fa[x];
    return fa[x] = findFa(fa[x]);
}

bool merge(int x, int y) {
    int fax = findFa(x), fay = findFa(y);
    if(fax == fay) return false;
    if(weight[fax] > weight[fay]) {
        fa[fay] = fax;
    } else {
        if(weight[fax] == weight[fay]) {
            weight[fay]++;
        }
        fa[fax] = fay;
    }
    return true;
}

int kruskal() {
    sort(edges.begin(), edges.end(), comp);
    int ans = 0, cnt = 0;
    bool flag = false;
    for(int i = 0;i < n-1;i++) {
        flag = false;
        for(auto [u, v, w] : edges) {
            if(merge(u, v)) {
                ans += w;
                cnt++;
                flag = true;
            }
        }
        if(!flag && cnt == n-1) break;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    weight.resize(n+1, 0);
    fa.resize(n+1);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int w;
            cin >> w;
            if(w && j <= i) {
                edges.push_back({i, j, w});
            }
        }
    }
    cout << kruskal();
    return 0;
}