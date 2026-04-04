#include<bits/stdc++.h>
using namespace std;

// vector<int> multi(const vector<int>& a, int b) {
//     vector<int>result;
//     int len = a.size();
//     for(int i = 0;i < len;i++) {
//         result.push_back(a[i] * b);
//     }
//     for(int i = 0;i < len-1;i++) {
//         result[i+1] += result[i]/10;
//         result[i] %= 10;
//     }
//     while(result.back() >= 10) {
//         int temp = result.back();
//         result.back() %= 10;
//         result.push_back(temp / 10);
//     }
//     if(result.size() > 500) {
//         result.resize(500);
//     }
//     return result;
// }
//高精度乘，大整数*大整数
vector<int> multi(const vector<int>& a, const vector<int>& b) {
    vector<int>result(501); //只保留500位，最后一位用来处理进位
    int len1 = a.size(), len2 = b.size();
    for(int i = 0;i < len1;i++) {
        for(int j = 0;j < len2;j++) {
            if(i + j >= 500) continue;
            result[i+j] += a[i] * b[j];
        }
    }
    for(int i = 0;i < 500;i++) {
        result[i+1] += result[i] / 10;
        result[i] %= 10;
    }
    while(result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}
int main() {
    int p;
    cin >> p;
    vector<int>result(1, 1);
    vector<int>base(1, 2);
    //对于任意一个正整数N，它的十进制位数为 ⌊log10​(N)⌋+1 而这里N = 2^p，对数可以把指数放在外面
    int digits = (int)(p * log10(2)) + 1;
    // p = 13 1101 ：8 + 4 + 1
    while(p) {
        if(p & 1) result = multi(result, base);
        base = multi(base, base);
        p >>= 1;
    }
    result[0] -= 1;
    cout << digits;
    if(digits < 500) {
        result.resize(500, 0); //如果位数不够500，则补0
    }
    for(int i = 499;i >= 0;i--) {
        if((i + 1) % 50 == 0) {
            cout << endl;
        }
        cout << result[i];
    }
    return 0;
}