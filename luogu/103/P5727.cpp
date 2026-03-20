#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    int len = 1;
    vector<int>n;
    n.push_back(num);
    while(num != 1) {
        if(num % 2 == 1) {
            num = num * 3 + 1;
        } else {
            num /= 2;
        }
        n.push_back(num);
        len++;
    }
    for(int i = len-1;i>=0;i--){
        cout << n[i] << ' ';
    }
    return 0;
}