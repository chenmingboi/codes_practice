#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b) {
    return a < b;
}
int main() {
    vector<int>num;
    for(int i = 0;i < 6;i++) {
        string s;
        cin >> s;
        int n = 0;
        if(s=="one"||s=="a"||s=="first"||s=="another"){n=1; }
        if(s=="two"||s=="both"||s=="second"){n=4; }
        if(s=="three"||s=="third"){n=9; }
        if(s=="four"){n=16; }
        if(s=="five"){n=25; }
        if(s=="six"){n=36; }
        if(s=="seven"){n=49; }
        if(s=="eight"){n=64; }
        if(s=="nine"){n=81; }
        if(s=="eleven"){n=21; }
        if(s=="twelve"){n=44; }
        if(s=="thirteen"){n=69; }
        if(s=="fourteen"){n=96; }
        if(s=="fifteen"){n=25; }
        if(s=="sixteen"){n=56; }
        if(s=="seventeen"){n=89; }
        if(s=="eighteen"){n=24; }
        if(s=="nineteen"){n=61; }
        num.push_back(n);
    }
    sort(num.begin(), num.end(), comp);
    int start = 0;
    while(num[start] == 0 && start < 6) start++;
    if(start == 6) {
        cout << 0;
        return 0;
    }
    cout << num[start];
    start++;
    //除了第一个小于10的可以直接输出，其他小于10的前面要提前输出一个0
    for(int i = start;i < 6;i++) {
        if(num[i] < 10) {
            cout << 0 << num[i];
        } else {
            cout << num[i];
        }
    }
    //上面的另一种写法
    /*
    bool flag = false;
    for(int i = 0;i < 6;i++) {
        if(flag) {
            if(num[i] < 10) {
                cout << 0 << num[i];
            } else {
                cout << num[i];
            } 
            // printf("%.2d", num[i]);
        } else {
            if(num[i] != 0) {
                cout << num[i];
                flag = true;
            }
        }
    }
    if(!flag) cout << 0;
    */
    return 0;
}