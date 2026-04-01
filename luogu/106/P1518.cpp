#include<bits/stdc++.h>
using namespace std;

vector<vector<char>>this_map(12, vector<char>(12));

void move(int& pos_x, int& pos_y, int& dir) {
    if(dir == 0) {
        if(this_map[pos_x-1][pos_y] != '*') {
            pos_x -= 1;
        } else {
            dir += 1;
        }
    } else if(dir == 1) {
        if(this_map[pos_x][pos_y+1] != '*') {
            pos_y += 1;
        } else {
            dir += 1;
        }
    } else if(dir == 2) {
        if(this_map[pos_x+1][pos_y] != '*') {
            pos_x += 1;
        } else {
            dir += 1;
        }
    } else if(dir == 3) {
        if(this_map[pos_x][pos_y-1] != '*') {
            pos_y -= 1;
        } else {
            dir = 0;
        }
    }
}
int main() {
    int pos_x1, pos_y1, pos_x2, pos_y2, dir1 = 0, dir2 = 0, time = 0;
    //dir=0表示向上走，dir=1向右，dir=2向下，dir=3向左
    unordered_map<string, bool> his; //默认初始化为false
    for(int i = 0;i < 12;i++) {
        this_map[0][i] = '*';
        this_map[i][0] = '*';
        this_map[11][i] = '*';
        this_map[i][11] = '*';
    }
    for(int i = 1;i <= 10;i++) {
        for(int j = 1;j <= 10;j++) {
            cin >> this_map[i][j];
            if(this_map[i][j] == 'F') {
                pos_x1 = i, pos_y1 = j; //Farmer
                this_map[i][j] = '.';
            } else if(this_map[i][j] == 'C') {
                pos_x2 = i, pos_y2 = j; // niu
                this_map[i][j] = '.';
            }
        }
    }
    bool flag = true;
    while(pos_x1 != pos_x2 || pos_y1 != pos_y2) {
        string str = to_string(pos_x1) + to_string(pos_y1) + to_string(dir1)
                    + to_string(pos_x2) + to_string(pos_y2) + to_string(dir2);
        //通过查找历史中有没有和当前时刻两者状态相同的时刻，如果有的话那就是发生循环，永远不会相遇
        if(his[str]) {
            flag = false;
            break;
        }
        his[str] = true;
        move(pos_x1, pos_y1, dir1);
        move(pos_x2, pos_y2, dir2);
        time++;
    }
    if(!flag) {
        cout << 0;
    } else {
        cout << time;
    }
    return 0;
}