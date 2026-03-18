#include<bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if(n<=1) {
        return false;
    }
    if(n <= 3) {
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 4;i*i < n;i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    vector<int>cishu(27,0);
    string word;
    cin >> word;
    for(auto it : word) {
        cishu[it-'a']++;
    }
    int maxn = INT_MIN, minn = INT_MAX;
    for(int i = 0;i < 27;i++) {
        maxn = max(maxn, cishu[i]);
        if(cishu[i] != 0) {
            minn = min(minn, cishu[i]);
        }
    }
    if(isPrime(maxn-minn)) {
        cout << "Lucky Word" << endl << maxn-minn;
    } else {
        cout << "No Answer"  << endl << 0;
    }
    return 0;
}