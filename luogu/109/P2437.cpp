#include<bits/stdc++.h>
using namespace std;

//样例超出了ll的范围，要用高精度加法

vector<int> add_gao(vector<int> a, vector<int> b) {
    //默认倒序001
    int lena = a.size(), lenb = b.size(), len = 0;
    if(lena <= lenb) {
        len = lenb;
        for(int i = 0;i < lenb-lena;i++) {
            a.push_back(0);
        }
    } else {
        len = lena;
        for(int i = 0;i < lena - lenb;i++) {
            b.push_back(0);
        }
    }
    vector<int>result(len+1, 0);
    for(int i = 0;i < len;i++) {
        result[i] = a[i] + b[i];
    }
    for(int i = 0;i < len;i++) {
        result[i+1] += result[i] / 10;
        result[i] %= 10;
    }
    while(result.size() >= 1 && result.back() == 0) result.pop_back();
    return result;
}
//优化过后的高精度加法实现
vector<int> add(const vector<int>& a, const vector<int>& b) {
    int lena = a.size(), lenb = b.size();
    int len = max(lena, lenb);
    vector<int>result(len, 0);
    int carry = 0;//进位
    for(int i = 0;i < len;i++) {
        int sum = carry;
        if(i < lena) sum += a[i];
        if(i < lenb) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    if(carry) result.push_back(carry);
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int>ini(1, 1);
    vector<vector<int>>mem(1005);
    mem[m] = ini;
    for(int i = m+1;i <= n;i++) {
        if(i - 2 >= 1) {
            mem[i] = add_gao(mem[i-1], mem[i-2]);
        } else if(i - 1 >= 1) {
            mem[i] = mem[i-1];
        }
    }
    reverse(mem[n].begin(), mem[n].end());
    for(auto it : mem[n]) {
        cout << it;
    }
    return 0;
}