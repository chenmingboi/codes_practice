#include<bits/stdc++.h>
using namespace std;

vector<int> mul_large(const vector<int>& a, const vector<int>& b) {
    int len1 = a.size(), len2 = b.size();
    vector<int>ans(len1+len2, 0);
    for(int i = 0;i < len1;i++) {
        for(int j = 0;j < len2;j++) {
            ans[i+j] += a[i] * b[j];
        }
    }
    int jinwei = 0;
    for(int i = 0;i < len1+len2;i++) {
        ans[i] += jinwei;
        jinwei = ans[i] / 10;
        ans[i] %= 10;
    }
    while(ans.back() == 0 && !ans.empty()) ans.pop_back();
    //防止结果为0的情况
    if(ans.empty()) ans.push_back(0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    vector<int>num1(len1), num2(len2), ans;
    for(int i = len1-1;i >= 0;i--) {
        num1[len1-1-i] = s1[i]-'0';
    }
    for(int i = len2-1;i >= 0;i--) {
        num2[len2-1-i] = s2[i]-'0';
    }
    ans = mul_large(num1, num2);
    reverse(ans.begin(), ans.end());
    for(auto it : ans) {
        cout << it;
    }
    return 0;
}