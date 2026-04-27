#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    //用map比较合适
    map<string, int>x; //第一个值string 为key， 第二个int为值 value
    for(int i = 0;i < q;i++) {
        int op;
        cin >> op;
        if(op == 1) {
            string name;
            int score;
            cin >> name >> score;
            x[name] = score;
            cout << "OK" << endl;
        } else if(op == 2) {
            string name;
            cin >> name;
            auto it = x.find(name);//返回指向key的迭代器
            if(it == x.end()) {
                cout << "Not found" << endl;
            } else {
                cout << it->second << endl;
            }
        } else if(op == 3) {
            string name;
            cin >> name;
            auto it = x.find(name);
            if(it == x.end()) {
                cout << "Not found" << endl;
            } else {
                x.erase(it);
                cout << "Deleted successfully" << endl;
            }
        } else if(op == 4) {
            cout << x.size() << endl;
        }
    }
    return 0;
}