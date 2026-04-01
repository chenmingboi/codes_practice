#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string result;
    vector<int>xishu(n+1);
    for(int i = 0;i < n+1;i++) {
        cin >> xishu[i];
    }
    if(n >= 1) {
        if(xishu[0] == 1) {
            result += (n==1) ? ("x") : ("x^" + to_string(n));
        } else if(xishu[0] == -1) {
            result += (n==1) ? ("-x") : ("-x^" + to_string(n));
        } else {
            result += to_string(xishu[0]) + ((n==1) ? ("x") : ("x^" + to_string(n)));
        }
        for(int i = 1;i < n;i++) {
            if(xishu[i] > 0) {
                if(xishu[i] == 1) {
                    result += (n-i == 1) ? ("+x") : ("+x^" + to_string(n-i));
                } else {
                    result += "+" + to_string(xishu[i]) + ((n-i == 1) ? ("x") : ("x^" + to_string(n-i)));
                }
            } else if(xishu[i] < 0) {
                if(xishu[i] == -1) {
                    result += (n-1 == 1) ? ("-x") : ("-x^" + to_string(n-i));
                } else {
                    result += to_string(xishu[i]) + ((n-i == 1) ? ("x") : ("x^" + to_string(n-i)));
                }
            } else if(xishu[i] == 0) {
                continue;
            }
        }
        if(xishu[n] > 0) {
            result += "+" + to_string(xishu[n]);
        } else if(xishu[n] < 0) {
            result += to_string(xishu[n]);
        }
    } else {
        result += to_string(xishu[0]);
    }
    
    cout << result;
    return 0;
}