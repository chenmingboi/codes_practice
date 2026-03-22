#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    if(num <= 2) return true;
    for(int i = 2;i*i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for(int i = 4;i <= n;i+=2) {
        for(int j = 2;j <=i;j++) {
            if(isPrime(j) && isPrime(i-j)) {
                cout << i << '=' << j << '+' << i-j << endl;
                break;
            }
        }
    }
    return 0;
}