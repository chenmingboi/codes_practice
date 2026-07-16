#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;
    if(num == 2 || num == 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i = 5;i*i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 2;i*i <= n;i++) {
        if(n % i == 0) {
            if(isPrime(i)) {
                cout << n / i;
                break;
            }
        }
    }
    return 0;
}