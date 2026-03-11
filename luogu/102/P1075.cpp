#include<bits/stdc++.h>
using namespace std;

//这道题一眼看上去没有思路emmmm...

//看了眼题解，用了个数学性质，一个数可以写成两个质数的乘积
/*
为什么第一个找到的因数一定是质数？
假设 i 是第一个能整除 n 的数（从 2 开始枚举）：
如果 i 是合数，则 i 有更小质因数 j < i
那么 j 也能整除 n，与 "i 是第一个" 矛盾
所以 i 必为质数 ✓*/
int main(){
    int n;
    cin >> n;
    for(int i = 2;i < n;i++){
        if(n % i == 0) {
            cout << n / i;
            return 0;
        }
    }
}