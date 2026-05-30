#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    if(num == 2 || num == 3) return true;
    for(int i = 4;i * i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans;
    cin >> n;
    for(int i = 2;i*i <= n;i++) {
        if(n % i == 0) {
            if(isPrime(i)) {
                ans = n / i;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}