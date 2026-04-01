#include<bits/stdc++.h>
using namespace std;

int main() {
    string a_str, b_str, result_str;
    cin >> a_str >> b_str;
    if(a_str == "0" || b_str == "0"){
        cout << 0;
        return 0;
    }
    vector<int>a, b;
    //尝试将每个数字放进数组里面
    int len1 = a_str.length(), len2 = b_str.length();
    vector<int>result(len1+len2, 0);
    for(int i = len1 - 1;i >= 0;i--) {
        a.push_back(a_str[i]-'0');
    }
    for(int i = len2 - 1;i >= 0;i--) {
        b.push_back(b_str[i]-'0');
    }
    //先累加不进位
    for(int i = 0;i < len1;i++) {
        for(int j = 0;j < len2;j++) {
            result[i+j] += a[i] * b[j];
        }
    }
    //统一处理进位
    for(int i = 0;i < len1+len2-1;i++) {
        result[i+1] += result[i]/10;
        result[i] %= 10;
    }
    int pos = len1+len2-1;
    while(result[pos] == 0) {
        pos--;
        if(pos < 0) break;
    }
    if(pos==-1) {
        cout << 0;
    } else {
        for(int i = pos;i >= 0;i--) {
            cout << result[i];
        }
    }
    return 0;
}