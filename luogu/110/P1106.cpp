#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n, result;
    int k, len, tempk;
    cin >> n >> k;
    len = n.length();
    tempk = k;
    int left = 0;
    int min_index;
    while(k && result.length() != len-tempk) {
        int min = 10;
        //这里i < left + k + 1多选一个，面对把前面的k的数都要pop掉的情况
        for(int i = left;i < left+k+1 && i < len;i++) {
            if(n[i]-'0' < min) {
                min_index = i;
                min = n[i]-'0';
            }
        }
        //先更新k
        k -= min_index - left;
        //求出了left - left+k中间最小数字所在的下标
        //更新left = min_index + 1;//下次从最小数字右侧开始扫描
        left = min_index + 1;
        result += n[min_index];//最左侧选择最小的
        //更新k

    }
    if(result.length() != len-tempk) {
        for(int i = min_index+1;i < len;i++) {
            result += n[i];
        }
    }
    int start_index = 0;
    while(result[start_index] == '0' && start_index < len-tempk) {
        start_index++;
    }
    if(start_index == len-tempk) {
        cout << 0;
    } else {
        for(int i = start_index;i < len-tempk;i++) {
            cout << result[i];
        }
    }
    return 0;
}