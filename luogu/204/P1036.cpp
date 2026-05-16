#include<bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
vector<int>x;

bool isPrime(int num) {
    if(num == 1) return false;
    if(num == 2 || num == 3) return true;
    if(num % 2 == 0 || num % 3 == 0) return false;
    for(int i = 4;i * i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int sum, int cnt, int index) {
    if(cnt == k) {
        if(isPrime(sum)) {
            ans++;
        }
        return;
    }
    if(index >= n) return;
    //减枝处理，如果从当前index到数组最后的num数量少于k-cnt那么肯定不成立，所以舍去
    if(k-cnt > n-index) return;
    //从当前index往后遍历数组dfs
    //其实没必要创建choose bool数组，因为选和不选是通过sum+x[index]和cnt体现出来的
    //在选择k个数的递归过程中下标只会递增，不会重复选择
    //且在递归结束之后通过回溯消除之前选择的状态
    for(int i = index;i < n;i++) {
        //对于每个数字有选或者不选的选择
        // if(choose[i] == false) {
        //选
        cnt++;
        sum += x[i];
        dfs(sum, cnt, i+1);
        //回溯不选
        sum -= x[i];
        cnt--;
        // }
    }
    // //方案二直接递归
    // //选
    // dfs(sum+x[index], cnt+1, index+1);
    // //不选
    // dfs(sum, cnt, index+1);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    x.resize(n);
    for(int i = 0;i < n;i++) {
        cin >> x[i];
    }
    dfs(0, 0, 0);
    cout << ans;
}