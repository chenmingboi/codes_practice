#include<bits/stdc++.h>
using namespace std;

//高精度加法，数据范围超出了long long的要求，可以使用string来处理，对长度较短的进行补0
//标记进位，然后对于最后一位要特殊处理，如果进位标记为true,result最后要多一个1
int main() {
    string a,b, result;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len1 = a.length(), len2 = b.length(), len = max(len1, len2);
    if(len1 < len2) {
        a.append(len2-len1, '0');
    } else {
        b.append(len1-len2, '0');
    }
    bool jinwei = false;
    for(int i = 0;i < len;i++) {
        int num1 = a[i]-'0', num2 = b[i]-'0', num;
        if(jinwei) num1 += 1;
        if(num1 + num2 >= 10) {
            num = num1 + num2 - 10;
            jinwei = true;
        } else {
            num = num1 + num2;
            jinwei = false;
        }
        result.push_back(num + '0');
    }
    if(jinwei) result.push_back('1');
    reverse(result.begin(), result.end());
    cout<< result;
    return 0;
}