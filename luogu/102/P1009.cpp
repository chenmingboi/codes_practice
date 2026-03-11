#include<bits/stdc++.h>
using namespace std;


// 高精度乘法：大整数 × 小整数（int）
vector<int> mul(vector<int>& a, int b) {
    vector<int> c;
    int t = 0; //进位
    for(int i = 0;i < a.size() || t;i++) {
        if(i < a.size()) t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    //如果a符合正常数字存储没有前导0，这里就不用去除前导0
    // while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

// 高精度加法：大整数 + 大整数
vector<int> add(vector<int>& a, vector<int>& b) {
    vector<int>c;
    int t = 0; //进位
    for(int i = 0;i < a.size() || i < b.size() || t;i++) {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
int main()
{
    // 由于本题中n <= 50 阶乘相加结果大于longlong,考虑使用vector<int>来存储数字，每一位对应于数组中的一个数字
    // 用倒序存储，个位是数组的第一个元素

    int n;
    cin >> n;
    vector<int>sum(1, 0);
    vector<int>fact(1, 1);
    for(int i = 1;i <= n;i++) {
        fact = mul(fact, i);
        sum = add(sum, fact);
    }
    int len = sum.size();
    for(int i = len-1;i >= 0;i--){
        cout << sum[i];
    }
    return 0;
}