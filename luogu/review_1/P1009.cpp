#include<bits/stdc++.h>
using namespace std;

vector<int> large_mul(const vector<int>&a, const int& b) {
    int len = a.size() + 2, lena = a.size();
    vector<int>result(len, 0);
    for(int i = 0;i < lena;i++) {
        result[i] = a[i] * b;
    }
    int jinwei = 0;
    for(int i = 0;i < len;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    while(result.size() > 0 && result.back() == 0) result.pop_back();
    return result;
}

vector<int> large_add(const vector<int>& a, const vector<int>& b) {
    int len = max(a.size(), b.size()) + 1, lena = a.size(), lenb = b.size();
    vector<int>result(len);
    for(int i = 0;i < len-1;i++) {
        if(i < lena && i < lenb) {
            result[i] = a[i] + b[i];
        } else if(i >= lenb) {
            result[i] = a[i];
        } else {
            result[i] = b[i];
        }
    }
    int jinwei = 0;
    for(int i = 0;i < len;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10; 
    }
    while(result.size() != 0 && result.back() == 0) result.pop_back();
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>result = {1}, temp = {1};
    for(int i = 2;i <= n;i++) {
        temp = large_mul(temp, i);
        result = large_add(result, temp);
    }
    int len = result.size();
    for(int i = len-1;i >= 0;i--) cout << result[i];
    return 0;
}