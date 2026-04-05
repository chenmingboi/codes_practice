#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    //这里要用long long 因为n*m*n大于了int的范围
    long long num1 = 0, num2 = 0;
    //正方形
    for(int i = 1;i <= n;i++) {
        num1 += (m+1-i) * (n+1-i);
    }
    //长方形
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(j != i) num2 += (m+1-j) * (n+1-i);
        }
    }
    cout << num1 << ' ' << num2;
}