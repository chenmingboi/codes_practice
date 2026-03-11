#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int result = 1;
    int max_len = 1;
    int last_num = 0;
    cin >> last_num;
    for(int i = 1;i < n;i++){
        int num;
        cin >> num;
        if(num == last_num + 1) {
            max_len += 1;
        } else {
            result = max(result ,max_len);
            max_len = 1;
        }
        last_num = num;
    }
    result = max(result, max_len); //最长连续的是在最后，需要在循环外再次更新一下
    cout << result;
    return 0;
}