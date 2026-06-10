#include<bits/stdc++.h>
using namespace std;

vector<int>mul_large(const vector<int>& a, const int& b) {
    int len = a.size();
    vector<int>result(len+5, 0);
    for(int i = 0;i < len;i++) {
        result[i] = a[i] * b;
    }
    int jinwei = 0;
    for(int i = 0;i < len+5;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    while(result.back() == 0 && result.size() != 1) result.pop_back();
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a;
    if(n == 3) {
        cout << "1 2" << '\n' << 2;
        return 0;
    } else if(n == 4) {
        cout << "1 3" << '\n' << 3;
        return 0;
    }
    int sum = 0, len = 0;
    for(int i = 2;i < n;i++) {
        if(sum + i <= n) {
            sum += i;
            a.push_back(i);
            len++;
        } else {
            break;
        }
    }
    int left = n-sum;
    for(int i = len-1;i >= 0;i--) {
        //这里要先判断left是否为0防止left <= 0还对a[i]进行加
        if(left == 0) break;
        a[i]++;
        left--;
    }
    a[len-1] += left;
    vector<int>ans(1, 1);
    for(int i = 0;i < len;i++) {
        ans = mul_large(ans, a[i]);
    }
    reverse(ans.begin(), ans.end());
    for(auto it : a) {
        cout << it << ' ';
    }
    cout << endl;
    for(auto it : ans) {
        cout << it;
    }
    return 0;
}