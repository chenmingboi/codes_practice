#include<bits/stdc++.h>
using namespace std;

int n, r;

void dfs(vector<int>& result, int left) {
    if(result.size() == r) {
        for(auto it : result) {
            cout << setw(3) << it;
        }
        cout << endl;
        return;
    }
    for(int i = left;i <= n;i++) {
        result.push_back(i);
        dfs(result, i+1);
        result.pop_back();
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r;
    vector<int>result;
    dfs(result, 1);
    return 0;
}