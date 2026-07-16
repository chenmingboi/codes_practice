#include<bits/stdc++.h>
using namespace std;

vector<int> large_mul(const vector<int>& a, const vector<int>& b, int len1, int len2) {
    vector<int>result(len1+len2, 0);
    for(int i = 0;i < len1;i++) {
        for(int j = 0;j < len2;j++) {
            result[i+j] += a[i] * b[j];
        }
    }
    int jinwei = 0;
    for(int i = 0;i < len1+len2;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    while(result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    vector<int>num1, num2;
    int len1 = s1.length(), len2 = s2.length();
    for(int i = len1-1;i >= 0;i--) num1.push_back(s1[i]-'0');
    for(int i = len2-1;i >= 0;i--) num2.push_back(s2[i]-'0');
    vector<int>result = large_mul(num1, num2, len1, len2);
    int len = result.size();
    for(int i = len-1;i >= 0;i--) cout << result[i];
    return 0;
}