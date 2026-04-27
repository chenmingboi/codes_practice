#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    unordered_map<string, set<int>>words;
    for(int i = 1;i <= n;i++) {
        int l;
        cin >> l;
        for(int j = 0;j < l;j++) {
            string word;
            cin >> word;
            words[word].insert(i);
        }
    }
    cin >> m;
    for(int i = 0;i < m;i++) {
        string word;
        cin >> word;
        for(auto it : words[word]) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}