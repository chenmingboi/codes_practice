#include<bits/stdc++.h>
using namespace std;

int n;

void dfs(vector<int>&result) {
    if(result.size() == n) {
        for(auto it : result) {
            cout << setw(5) << it;
        }
        cout << '\n';
        return;
    }
    for(int i = 1;i <= n;i++) {
        if(find(result.begin(), result.end(), i) != result.end()) {
            continue;
        } else {
            result.push_back(i);
            dfs(result);
            result.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int>result;
    dfs(result);
    return 0;
}