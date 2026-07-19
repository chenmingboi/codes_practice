#include<bits/stdc++.h>
using namespace std;

int n;

struct person {
    char sex;
    int index;
    int jishu;
    int left;
    int right;
    bool chudui;
};

struct NodePair {
    int left;
    int right;
    int chazhi;
    // //要和原来的意思相反以实现和原来排序相反的结果
    // bool operator<(const NodePair& other) const {
    //     if(chazhi != other.chazhi) {
    //         return chazhi > other.chazhi;
    //     }
    //     return left > other.left;
    // }
};

//priority_queue默认是大根堆，可以通过重载符号来实现小根堆
// priority_queue<NodePair>minHeap;

//更推荐显式写比较器
struct comp {
    bool operator() (const NodePair& a, const NodePair& b) const {
        if(a.chazhi != b.chazhi) {
            return a.chazhi > b.chazhi;
        } 
        return a.left > b.left;
    }
};
//实现了小根堆
priority_queue<NodePair, vector<NodePair>, comp>minHeap;

bool add_pair(vector<person>& persons, int index1, int index2) {
    if(index1 <= 0 || index2 > n) return false;
    if(persons[index1].chudui || persons[index2].chudui) return false;
    if(persons[index1].sex == persons[index2].sex) return false;
    minHeap.push({index1, index2, abs(persons[index1].jishu - persons[index2].jishu)});
    persons[index1].chudui = true, persons[index2].chudui = true;
    int leftPersonIndex = persons[index1].left;
    int rightPersonIndex = persons[index2].right;
    persons[leftPersonIndex].right = rightPersonIndex;
    persons[rightPersonIndex].left = leftPersonIndex;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string s1;
    cin >> s1;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<person>persons(n+2);
    //引入哨兵节点0, n+1
    for(int i = 1;i <= n;i++) {
        persons[i].index = i;
        persons[i].chudui = false;
        persons[i].jishu = a[i];
        persons[i].sex = s1[i-1];
        persons[i].left = i-1;
        persons[i].right = i+1;
    }
    persons[0].right = 1;
    persons[n+1].left = n;
    bool flag = false;
    int cnt = 0;
    do {
        flag = false;
        for(int i = 1;i <= n;) {
            if(persons[i].chudui) {
                i++;
                continue;
            }
            int next = persons[i].right;
            if(add_pair(persons, i, persons[i].right)) {
                cnt++;
                flag = true;
                i = persons[next].right;
            } else {
                i = next;
            }
        }
    }while(flag);
    cout << cnt << endl;
    while(!minHeap.empty()) {
        auto it = minHeap.top();
        cout << it.left << ' ' << it.right << '\n';
        minHeap.pop();
    }
    return 0;
}