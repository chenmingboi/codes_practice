#include<bits/stdc++.h>
using namespace std;

bool ishuiwen(int num) {
    string str = to_string(num);
    int len = str.length();
    for(int i = 0, j = len-1;i <= j;i++,j--) {
        if(str[i] != str[j]) return false;
    }
    return true;
}

bool isPrime(int num) {
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i = 2;i <= sqrt(num);i++) {
        if(num % i == 0) return false;
    }
    return true;
}
int main() {
    int a, b;
    cin >> a >> b;
    vector<int>result;
    for(int i = a;i <= b;i++) {
        //把简单判断且筛除较多的放在前面
        //一筛
        if(i % 2 == 0 || i % 3 == 0) continue;
        //二筛
        if(ishuiwen(i)) {
            //三晒
            if(isPrime(i)) {
                result.push_back(i);
            }
        }
    }
    for(auto it : result) {
        cout << it << endl;
    }
    return 0;
}