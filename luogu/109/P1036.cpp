#include<bits/stdc++.h>
using namespace std;

//现在又是每个数只有两种选择，选或者不选，如果用递归
//将会是指数级的复杂度2^n，但是这道题中n最大时20，貌似可以尝试一下
//确实没有TLE，但是尝试一下是否可以优化一下复杂度
vector<int>result;
vector<int>x;
int n, k, ans=0;
bool isPrime(int num) {
    if(num <= 1) return false;
    if(num == 2 || num == 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i = 2;i * i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}
void digui(int i, int pos, int sum) {
    if(i == 0) {
        if(isPrime(sum)) ans++;
        return;
    }
    //数组中剩余数的数量少于还要挑选的数量的时候可以直接return
    if(n-pos < i) return;
    if(pos >= n || i < 0) {
        return;
    }
    //选当前这个数
    digui(i-1, pos+1, sum+x[pos]);
    //不选这个数
    digui(i, pos+1, sum);
}

int main() {
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        x.push_back(num);
    }
    digui(k, 0, 0);
    cout << ans;
    return 0;
}

//问了下gpt，没有办法使用01背包，因为如果要看为01背包问题的话
//背包的容量在这道题中是数的和，太大了，要开三位数组
//目前的递归已经是比较好的方案，另外想要优化的话可以对dfs进行剪枝
//就是当剩余数的数量少于还要挑选数的数量时此时可以直接return
