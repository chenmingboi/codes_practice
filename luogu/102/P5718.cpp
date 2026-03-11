#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, result = INT_MAX;
    cin >> n;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        result = min(a, result);
    }
    cout << result;
    return 0;
}