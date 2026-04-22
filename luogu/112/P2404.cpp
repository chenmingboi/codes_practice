#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>result;
void dfs(const int& n, vector<int>&path, int sum) {
    if(sum > n) {
        return;
    }
    if(sum == n) {
        result.push_back(path);
        return;
    }
    if(sum < n) {
        int start = 0;
        if(path.empty()) {
            start = 1;
        } else {
            start = path.back();
        }
        for(int i = start;i < n;i++) {
            path.push_back(i);
            dfs(n, path, sum+i);
            path.pop_back();
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>path;
    dfs(n, path, 0);
    for(auto &shizi : result) {
        int len = shizi.size();
        for(int i = 0;i < len-1;i++) {
            cout << shizi[i] << '+';
        }
        cout << shizi[len-1];
        cout << endl;
    }
    return 0;
}