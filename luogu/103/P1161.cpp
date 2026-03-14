#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>light(2000003, 0);
    for(int i = 0;i < n;i++){
        double a;
        int t;
        cin >> a >> t;
        for(int j = 1;j <= t;j++){
            int temp = (int)(j * a);
            light[temp]++;
            light[temp] %= 2;
        }
    }
    for(int i = 0;i < 2000003;i++){
        if(light[i] == 1){
            cout << i;
            break;
        }
    }
    return 0;
}