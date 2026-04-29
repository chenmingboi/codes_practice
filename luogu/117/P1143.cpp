#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    string num, result;
    cin >> num;
    cin >> m;
    reverse(num.begin(), num.end());
    int len = num.length(), sum = 0;
    for(int i = 0;i < len;i++) {
        int temp = 0;
        if(isdigit(num[i])) {
            temp = (num[i]-'0') * pow(n, i);
        } else {
            temp = (num[i]-'A'+10) * pow(n, i);
        }
        sum += temp;
    }
    if(sum == 0) {
        cout << 0;
        return 0;
    }
    while(sum != 0) {
        //除2取余
        int temp = sum % m;
        if(temp >= 10) {
            result += char(temp-10+'A');
        } else {
            result += to_string(temp);
        }
        sum /= m;
    }
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}