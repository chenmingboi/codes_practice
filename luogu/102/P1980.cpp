#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int result = 0;
    for(int i = 1;i <= n;i++){
        int temp = i;
        while(temp != 0) {
            if(temp % 10 == x) {
                result++;
            }
            temp /= 10;
        }
    }
    cout << result;
    return 0;
}