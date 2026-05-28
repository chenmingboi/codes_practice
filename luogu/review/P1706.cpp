#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>ans;

void dfs(int len) {
    if(len > n) return;
    if(len == n) {
        for(auto it : ans) {
            cout << setw(5) << it;
        }
        cout << endl;
        return;
    }
    for(int i = 1;i <= n;i++) {
        if(find(ans.begin(),ans.end(), i) == ans.end()){
            ans.push_back(i);
            dfs(len+1);
            ans.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(0);
    return 0;
}