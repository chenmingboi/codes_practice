#include<bits/stdc++.h>
using namespace std;

vector<int>large_mul(const vector<int>& a, const int& b) {
    //默认a为反序
    int len = a.size();
    vector<int>ans(len+4);
    for(int i = 0;i < len;i++) {
        ans[i] = a[i] * b;
    }
    int jinwei = 0;
    for(int i = 0;i < len+4;i++) {
        ans[i] += jinwei;
        jinwei = ans[i] / 10;
        ans[i] %= 10;
    }
    while(ans.back() == 0 && !ans.empty()) {
        ans.pop_back();
    }
    return ans;
}

vector<int>large_add(const vector<int>& a, const vector<int>& b) {
    int len1= a.size(), len2 = b.size();
    int len = max(len1, len2), templen = min(len1, len2);
    vector<int>ans(len+1);
    int i = 0;
    for(;i < templen;i++) {
        ans[i] = a[i] + b[i];
    }
    while(i < len1) {
        ans[i] = a[i];
        i++;
    }
    while(i < len2) {
        ans[i] = b[i];
        i++;
    }
    int jinwei = 0;
    for(int j = 0;j < len+1;j++) {
        ans[j] += jinwei;
        jinwei = ans[j] / 10;
        ans[j] %= 10;
    }
    while(ans.back() == 0 && !ans.empty()) {
        ans.pop_back();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>ans(1, 1);
    vector<int>temp(1, 1);
    for(int i = 2;i <= n;i++) {
        ans = large_mul(ans, i);
        temp = large_add(temp, ans);
    }
    reverse(temp.begin(), temp.end());
    for(auto it : temp) {
        cout << it ;
    }
    return 0;
}