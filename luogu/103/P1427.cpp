#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr;
    int len = 0;
    for(int i = 0; ;i++){
        int num;
        cin >> num;
        if(num != 0) {
            arr.push_back(num);
            len++;
        } else{
            break;
        }
    }
    for(int i = len-1;i >= 0;i--){
        cout << arr[i] << ' ';
    }
    return 0;
}