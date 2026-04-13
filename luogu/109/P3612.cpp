#include<bits/stdc++.h>
using namespace std;

//MLE
// void digui(string& str) {
//     string temp = str;
//     char last = str.back();
//     temp.pop_back();
//     temp.insert(temp.begin(), last);
//     str += temp;
//     return;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    long long n;
    cin >> n;
    long long base = str.length();
    long long len = base;
    while(n > len) len *= 2;
    while(len > base) {
        long long half = len/2;
        if(n > half) {
            //这里要加判断条件，因为n可能在更新之后小于half
            long long k = n - half;
            if(k == 1){
                n = half;
            } else {
                n = k-1;
            }
        }
        len = half;
    }
    cout << str[n-1];
    return 0;
}