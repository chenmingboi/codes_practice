#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> b;
    int n = b.size();
    for(int i =  0;i < n-1;i++){
        cin >> a;
        b += a;
    }
    cout << n << ' ';
    int count0 = 0, count1 = 0, len = b.size();
    //优化思路将count0和count1合并，只保留一个计数器，判断标准改为b[i] == b[i-1]
    for(int i = 0;i < len;i++) {
        if(i == 0 && b[i] == '1') {
            cout << 0 << ' ';
            count1++; 
            continue;
        } else if(i==0 && b[i] == '0') {
            count0++;
            continue;
        }
        if(b[i] == '0' &&  b[i-1] == '0'){
            count0++;
        } else if(b[i] == '0' &&  b[i-1] != '0'){
            cout << count1 << ' ';
            count1 = 0;
            count0++;
        } else if(b[i] == '1' && b[i-1] != '1'){
            cout << count0 << ' ';
            count0 = 0;
            count1++;
        } else if(b[i]=='1' && b[i-1] == '1') {
            count1++;
        }
    }
    if(count1 != 0) {
        cout << count1;
    } else if(count0 != 0) {
        cout << count0;
    }
    return 0;
}