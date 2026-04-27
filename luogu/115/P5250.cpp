#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //此题考查 set 的方法
    set<int>wh;//warehouse
    int m;
    cin >> m;
    for(int i = 0;i < m;i++) {
        int op, len;
        cin >> op >> len;
        if(op == 1) {
            if(wh.find(len) != wh.end()) {
                cout << "Already Exist" << endl;
            } else {
                wh.insert(len);
            }
        } else if(op == 2) {
            if(wh.find(len) != wh.end()) {
                cout << len << endl;
                wh.erase(len);
            } else {
                if(wh.empty()) {
                    cout << "Empty" << endl; 
                } else {
                    auto la = wh.lower_bound(len); //返回大于或等于的迭代器
                    if(la == wh.end()) {
                        // cout << *(la-1) << endl; 这里set返回的迭代器不能加减
                        cout << *prev(la) << endl;
                        wh.erase(*prev(la));
                    } else {
                        if(la == wh.begin()) {
                            cout << *la << endl;
                            wh.erase(*la);
                        } else {
                            auto sm = prev(la);//小于len的
                            //注意这里要取小于等于号，因为当相等的时候要取比较短的
                            int er = (abs(*sm - len) <= abs(*la - len) ? *sm : *la);
                            cout << er << endl;
                            wh.erase(er);
                        }
                    }
                }
            }
        }
    }
    return 0;
}