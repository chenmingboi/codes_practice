#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>result;
    result.push_back(0);
    int num, count = 0, ans=0;
    while(ans < n*n) {
        cin >> num;
        ans += num;
        for(int i = 0;i < num;i++){
            result.push_back(count);
        }
        count++;
        count %= 2;
    }
    for(int i = 1;i <= n*n;i++){
        cout << result[i];
        if(i % n == 0 && i != 1 && i != n*n) {
            cout << endl;
        }
    }
    return 0;

}