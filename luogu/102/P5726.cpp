#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int min_price = INT_MAX, max_price = INT_MIN;
    int sum = 0;
    for(int i = 0;i < n;i++){
        int price;
        cin >> price;
        min_price = min(min_price, price);
        max_price = max(max_price, price);
        sum += price;
    }
    sum -= (min_price + max_price);
    double result = sum*1.0 / (n-2)*1.0;
    ostringstream oss;
    oss << fixed << setprecision(2) << result;
    cout << oss.str();
    return 0;

}