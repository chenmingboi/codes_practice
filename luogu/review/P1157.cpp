#include<bits/stdc++.h>
using namespace std;

int n, r;
vector<int>q;
void dfs(int start, int len) {
    if(len > r) return;
    if(len == r) {
        for(auto it : q) {
            cout << setw(3) << it;
        }
        cout << endl;
        //写在这里的话只会在最深层pop,外层并没有pop
        // q.pop_back();
        return;
    }
    for(int i = start;i <= n;i++) {
        q.push_back(i);
        dfs(i+1, len+1);
        //当前层pop掉i，回溯
        q.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r;
    dfs(1, 0);
    return 0;
}