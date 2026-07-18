#include<bits/stdc++.h>
using namespace std;

vector<int> large_mul(const vector<int>& a, const int& b) {
    int len = a.size();
    vector<int>result(len+6, 0);
    for(int i = 0;i < len;i++) {
        result[i] = a[i] * b;
    }
    int jinwei = 0;
    for(int i = 0;i < len+6;i++) {
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
    int n;
    cin >> n;
    vector<int>fenjie;
    int sum = 0, len = 0;
    //从2开始连续尝试
    for(int i = 2;i <= n;i++) {
        if(sum + i <= n) {
            fenjie.push_back(i);
            sum += i;
            len++;
        } else {
            break;
        }
    }
    int cha = n - sum;
    while(cha) {
        for(int i = len-1;i >= 0;i--) {
            fenjie[i] += 1;
            cha--;
            if(cha == 0) break;
        }
    }
    for(int i = 0;i < len;i++) cout << fenjie[i] << ' ';
    cout << endl;
    vector<int>result(1, 1);
    for(int i = 0;i < len;i++) {
        result = large_mul(result, fenjie[i]);
    }
    int len1 = result.size();
    for(int i = len1-1;i >= 0;i--) {
        cout << result[i];
    }
    return 0;
}