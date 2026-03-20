#include<bits/stdc++.h>
using namespace std;

//这道题第一时间的思路比较复杂但简单，就是创造一个长度为l+1的数组全部赋值为1
//再遍历地铁区域将1->0,如果已经是0保持不变，最后遍历初始数组找寻为1的个数
int main(){
    int l, m;
    cin >> l >> m;
    vector<int>malu(l+1, 1);
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        for(int j = u;j <= v;j++){
            if(malu[j] == 1) {
                malu[j] = 0;
            }
        }
    }
    int result = 0;
    for(int i = 0; i <= l;i++){
        if(malu[i] == 1) result++;
    }
    cout << result;
    return 0;
}