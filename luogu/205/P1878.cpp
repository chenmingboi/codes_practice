#include<bits/stdc++.h>
using namespace std;

int n;

struct person {
    char sex;
    int a;
    int index;
    int left_index;
    int right_index;
    bool chudui;
    person() : chudui(false) {}
};

struct Node {
    int diff;
    int l;
    int r;
    //priority_queue默认为大根堆，所以我们如果要获得小根堆的效果就要反着定义比较规则
    bool operator<(const Node& other) const {
        if(diff != other.diff) {
            return diff > other.diff;
        }
        return l > other.l;
    }
    Node(int di, int lx, int ly) : diff(di), l(lx), r(ly) {}
};

void add_pair(priority_queue<Node>& qp, const vector<person>&people, int l, int r) {
    if(l < 1 || r > n) return;
    if(people[l].sex == people[r].sex) return;
    if(people[l].chudui || people[r].chudui) return;
    int diff = abs(people[l].a - people[r].a);
    qp.push({diff, l, r});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //使用到了小顶堆以及链表
    cin >> n;
    vector<person>people(n+2);
    priority_queue<Node>q;
    for(int i = 1;i <= n;i++) {
        char s;
        cin >> s;
        people[i].sex = s;
        people[i].index = i;
        //这里使用哨兵节点0和n+1
        people[i].left_index = i-1;
        people[i].right_index = i+1;
    }
    people[0].right_index = 1;
    people[n+1].left_index = n;
    for(int i = 1;i <= n;i++) {
        cin >> people[i].a;
    }
    for(int i = 1;i < n;i++) {
        add_pair(q, people, i, i+1);
    }
    vector<pair<int, int>>ans;
    while(!q.empty()) {
        //取出插值最小的
        Node top = q.top();
        q.pop();
        int l = top.l, r = top.r;
        if(people[l].chudui || people[r].chudui) {
            continue;;
        }
        int l_l = people[l].left_index, r_r = people[r].right_index;
        add_pair(q, people, l_l, r_r);
        people[l].chudui = true, people[r].chudui = true;
        people[l_l].right_index = r_r;
        people[r_r].left_index = l_l;
        ans.push_back({l, r});
    }
    cout << ans.size() << endl;
    for(auto it : ans) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}