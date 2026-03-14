#include<bits/stdc++.h>
using namespace std;

//题目问的是有几个数可以表示成另外两个不相同的数之和，而不是有几个组合
int main(){
    int n, ans=0;
    cin >> n;
    vector<int>input;
    vector<bool>result(n, false);
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(j == i) continue;
            for(int k = j+1;k < n;k++){
                if(k == i) continue;
                if(input[i] == input[j]+input[k]) result[i]=true;
            }
        }
    }
    for(auto it : result) {
        if(it) ans++;
    }
    cout << ans;
    return 0;
}