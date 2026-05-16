#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, set<int>>cnt;
    for(int i = 1;i <= n;i++){
        int l;
        cin >> l;
        for(int j = 0;j < l;j++) {
            string word;
            cin >> word;
            cnt[word].insert(i);
        }
    }
    int m;
    cin >> m;
    for(int i = 0;i < m;i++) {
        string word;
        cin >> word;
        for(auto it : cnt[word]) {
            cout << it << ' ';
        }
        cout << endl;
    }
}