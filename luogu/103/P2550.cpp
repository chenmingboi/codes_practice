#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>zhongjiang(8, 0);
    vector<int>prize(7, 0);
    for(int i = 0;i < 7;i++){
        cin >> prize[i];
    }
    for(int i = 0;i < n;i++){
        int sum = 7;
        for(int j = 0;j < 7;j++){
            int num;
            cin >> num;
            for(int k = 0;k < 7;k++){
                if(num == prize[k]) sum--;
            }
        }
        zhongjiang[sum]++;
    }
    for(int i = 0;i < 7;i++){
        cout << zhongjiang[i] << ' ';
    }
    return 0;
}