#include<bits/stdc++.h>
using namespace std;

vector<int> add_large(vector<int>a, vector<int>b) {
    vector<int>result;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len1 = a.size(), len2 = b.size(), len = max(len1, len2);
    if(len1 < len2) {
        for(int i = 0;i < len2-len1;i++) a.push_back(0);
    } else {
        for(int i = 0;i < len1 - len2;i++) b.push_back(0);
    }
    int jw = 0;
    for(int i = 0;i < len;i++) {
        int num = a[i] + b[i] + jw;
        jw = num / 10;
        result.push_back(num % 10);
    }
    if(jw != 0) result.push_back(jw);
    reverse(result.begin(), result.end());
    return result;
}

vector<int> mul_large(vector<int>a, vector<int>b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len1 = a.size(), len2 = b.size(), len = len1 + len2;
    vector<int>result(len, 0);
    for(int i = 0;i < len1;i++) {
        for(int j = 0;j < len2;j++) {
            result[i+j] += a[i] * b[j];
        }
    }
    //处理进位
    for(int i = 0;i < len-1;i++) {
        result[i+1] += result[i]/10;
        result[i] %= 10;
    }
    while(result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    //下面去除前导0的逻辑有问题
    //这里会用旧的下标访问新的数组，result.pop_back()之后数组相对应的下标顺序会发生变化
    // for(int i = len-1;i > 0;i--) {
    //     if(result[i] == 0) result.pop_back();
    // }
    reverse(result.begin(), result.end());
    return result;
}
int main() {
    int n;
    cin >> n;
    vector<int>result(1,0);
    vector<int> fact(1,1);
    for(int i = 1;i <= n;i++) {
        vector<int> factor;
        int k = i;
        while(k) {
            factor.push_back(k % 10);
            k /= 10;
        }
        reverse(factor.begin(), factor.end());

        fact = mul_large(fact, factor); // 只乘一次
        result = add_large(result, fact);
    }
    for(auto it : result) {
        cout << it;
    }
    return 0;
}