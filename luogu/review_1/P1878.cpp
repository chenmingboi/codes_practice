#include<bits/stdc++.h>
using namespace std;

struct Person {
    char sex;
    int level;
    int left;
    int right;
    bool chudui;
    Person() {chudui = false;}
};

struct NodePair{
    int left;
    int right;
    int diff;
    //默认为大根堆，需要相反定义变成小根堆
    //默认为priority_queue<NodePair, vector<NodePair>, less<NodePair>q
    bool operator<(const NodePair& other) const {
        if(diff == other.diff) {
            return left > other.left;
        } else {
            return diff > other.diff;
        }
    }
};

int n;
priority_queue<NodePair>q;

void make_pair(int left, int right, const vector<Person>&people) {
    Person l = people[left]; Person r = people[right];
    if(l.chudui || r.chudui) return;
    if(l.sex == r.sex) return;
    if(left < 1 || right > n) return;
    int d = abs(l.level - r.level);
    q.push({left, right, d});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string sexy;
    cin >> sexy;
    vector<Person>people(n+2);
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        people[i].level = a;
        people[i].left = i-1;
        people[i].right = i+1;
        people[i].sex = sexy[i-1];
    }
    people[0].right = 1; people[n+1].left = n;
    for(int i = 1;i <= n;i++) {
        make_pair(i, people[i].right, people);
    }
    vector<pair<int, int>>ans;
    do{
        auto it = q.top();
        q.pop();
        int left = it.left, right = it.right;
        if(!people[left].chudui && !people[right].chudui) {
            ans.push_back({left, right});
            people[left].chudui = true, people[right].chudui = true;
            int l_l = people[left].left, r_r = people[right].right;
            people[l_l].right = r_r;
            people[r_r].left = l_l;
            make_pair(l_l, r_r, people);
        } 
    }while(!q.empty());
    cout << ans.size() << endl;
    for(auto it : ans) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}