#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int juzhen = 1, sanjiao = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(juzhen < 10) {
                cout << 0 << juzhen;
            } else {
                cout << juzhen;
            }
            juzhen++;
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(n - i - 1 > j) {
                cout << "  ";
            } else {
                if(sanjiao < 10) {
                cout << 0 << sanjiao;
                } else {
                    cout << sanjiao;
                }
                sanjiao++;
            }

        }
        cout << endl;
    }
    return 0;
}