#include<bits/stdc++.h>
using namespace std;

vector<int>sub_large(const vector<int>& a, const vector<int>& b) {
    int len1 = a.size(), len2 = b.size();
    vector<int>ans(len1, 0);
    for(int i = 0;i < len2;i++) {
        ans[i] = a[i] - b[i];
    }
    for(int i = len2;i < len1;i++) {
        ans[i] = a[i];
    }
    int jiewei = 0;
    for(int i = 0;i < len1;i++) {
        ans[i] -= jiewei;
        if(ans[i] < 0) {
            //因为a[i]-b[i]顶多是0-9为-9，不会出现-10及以下的数
            ans[i] += 10;
            jiewei = 1;
        } else {
            jiewei = 0;
        }
    }
    while(ans.back() == 0 && !ans.empty())  ans.pop_back();
    if(ans.empty()) ans.push_back(0);
    return ans;
}

bool judge(const string& a, const string& b) {
    if(a.length() > b.length()) return true;
    if(a.length() < b.length()) return false;
    int len = a.length();
    for(int i = 0;i < len;i++) {
        if(a[i] == b[i]) {
            continue;
        } else if(a[i] > b[i]) {
            return true;
        } else {
            return false;
        }
    }
    //两个数相等输出true，以防输出-0
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    bool fushu = false;
    if(!judge(a, b)) {
        swap(a, b);
        fushu = true;
    }
    int len1 = a.length(), len2 = b.length();
    vector<int>num1(len1), num2(len2), ans;
    for(int i = 0;i < len1;i++) {
        num1[i] = a[len1-1-i]-'0';
    }
    for(int i = 0;i < len2;i++) {
        num2[i] = b[len2-1-i]-'0';
    }
    ans = sub_large(num1, num2);
    reverse(ans.begin(), ans.end());
    if(fushu) {
        cout << '-';
    }
    for(auto it : ans) {
        cout << it;
    }
    return 0;
}