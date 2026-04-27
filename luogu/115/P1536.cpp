#include<bits/stdc++.h>
using namespace std;

vector<int>fa, ran;

int find(int x) {
    return (x == fa[x] ? fa[x] : find(fa[x]));
}

void merge(int i, int j) {
    int x = find(i), y = find(j);
    if(x == y) return;
    if(ran[x] < ran[y]) {
        fa[x] = y;
    } else {
        if(ran[x] == ran[y]) {
            ran[x]++;
        }
        fa[y] = x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin >> n) {
        if(n == 0) break;
        int m;
        cin >> m;
        fa.resize(n+1), ran.resize(n+1);
        for(int i = 1;i <= n;i++) {
            fa[i] = i; ran[i] = 1;
        }
        for(int i = 0;i < m;i++) {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        }
        set<int>jihe;
        for(int i = 1;i <= n;i++) {
            jihe.insert(find(i));
        }
        cout << jihe.size() - 1 << endl;
    }
    return 0;
}