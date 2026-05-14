#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    输入格式
第一行两个整数 n,k，表示共有 n 个数，木板可以盖住 k 个数。

第二行 n 个整数，表示矩阵中的元素。

输出格式
共 n−k+1 行，每行一个整数。

第 i 行表示第 i∼i+k−1 个数中最大值是多少。
    */
    int n, k;
    cin >> n >> k;
    //使用单调队列模板
    deque<int>q;//存储加入元素的下标
    vector<int>a(n+1, 0);//矩阵中的元素
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        //现在的i为窗口右侧的下标
        //1.把队列中过期的元素删除掉
        while(!q.empty() && q.front() < i-k+1) {
            // i-k+1对应的是窗口的左侧下标
            q.pop_front(); //因为q中的元素后加入的且不比之前加入元素大的元素是后加入的即下标要比已经加入的元素
            //下标小所以是从front进行pop过期元素
        }
        //2.把队列中所有比当前元素小的元素删除掉
        while(!q.empty() && a[q.back()] <= a[i]) {
            q.pop_back();
            //这样会保证后来的且大的元素排到队首，即保证了队列降序排序
        }
        //3.将当前元素加入进队列
        q.push_back(i);
        //4.判断当前是否已经满足一个窗口的长度
        if(i >= k) {
            cout << a[q.front()] << endl;
        }
    }
    return 0;
}