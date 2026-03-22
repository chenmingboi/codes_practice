#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if(num == 1) return false;
    if(num <= 3) return true;
    for(int i = 2;i * i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int a;
        cin >> a;
        if(isPrime(a)) {
            cout << a << ' ';
        }
    }
    return 0;
}