#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>a;
    for(int i = 0;i < n;i++) {
        int a_i;
        cin >> a_i;
        a.push_back(a_i);
    }
    for(int i = 0;i < n;i++) {
        int result = 0;
        for(int j = 0;j < i;j++){
            if(a[j] < a[i]) result++;
        }
        cout << result << ' ';
    }
    return 0;
}