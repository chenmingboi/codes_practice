#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    int k;
    cin >> n >> k;
    string ans;
    for(char c : n) {
        while(!ans.empty() && k > 0 && ans.back() > c) {
            k--;
            ans.pop_back();
        }
        ans.push_back(c);
    }
    while(k) {
        ans.pop_back();k--;
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    if(ans.size() == 0) ans = "0";
    cout << ans;
    return 0;
}