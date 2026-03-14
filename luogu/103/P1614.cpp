#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, ans=INT_MAX;
    cin >> n >> m;
    vector<int>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i <= n-m;i++){
        int sum = 0;
        for(int j = i;j < i+m;j++){
            sum += a[j];
        }
        ans = min(sum, ans);
    }
    cout << ans;
    return 0;
}