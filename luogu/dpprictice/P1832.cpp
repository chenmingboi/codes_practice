#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    if(num == 3 || num == 2) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i = 4;i*i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long>dp(n+1, 0);
    dp[0] = 1;
    vector<int>prime;
    for(int i = 2;i <= n;i++) {
        if(isPrime(i)) prime.push_back(i);
    }
    for(auto p : prime) {
        //以p结尾
        for(int i = p;i <= n;i++) {
            dp[i] += dp[i-p];
        }
    }
    cout << dp[n];
    return 0;
}