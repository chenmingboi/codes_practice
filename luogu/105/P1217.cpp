#include<bits/stdc++.h>
using namespace std;

bool isHuiwen(int num) {
    string num_str = to_string(num);
    int len = num_str.length();
    for(int i = 0, j = len-1;i <= j;i++, j--) {
        if(num_str[i] != num_str[j]) return false;
    }
    return true;
}

bool isPrime(int num) {
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num % 2 == 0|| num % 3 == 0) return false;
    for(int i = 2;i*i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}
int main() {
    int a, b;
    cin >> a >> b;
    for(int i = a;i <= b;i++) {
        //有时间限制，这里可以提前滤过一些数
        if(i % 2 == 0 || i % 3 == 0) continue;
        if(isHuiwen(i)) {
            if(isPrime(i)){
                cout << i << endl;
            }
        }
    }
    return 0;
}