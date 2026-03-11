#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num[10];
    char ch;
    bool result = false;
    for(int i = 0,j = 0;i < 12;i++){
        char in;
        cin >> in;
        if(in != '-'){
            num[j++] = in - '0';
        }
    }
    cin >> ch;
    int judge = 0;
    for(int i = 0;i < 9;i++) {
        judge += num[i] * (i + 1);
    }
    judge %= 11;
    char judge_ch = (judge == 10) ? 'X' : (judge + '0');
    if(ch == judge_ch) {
        cout << "Right";
    } else {
        for(int i = 0; i < 9;i++) {
            cout << num[i];
            if(i == 0 || i == 3 || i == 8) {
                cout << '-';
            }
        }
        cout << judge_ch;
    }
    return 0;
}