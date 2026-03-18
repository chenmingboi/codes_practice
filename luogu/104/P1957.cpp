#include<bits/stdc++.h>
using namespace std;


void main1(char last_op, int case_id, string input_part) {
    int num1, num2, op_result=0;
    if(case_id == 1) {
        cin >> num1 >> num2;
    } else {
        num1 = stoi(input_part);
        cin >> num2;
    }
    if(last_op == 'a') {
        last_op = '+';
        op_result = num1 + num2;
    } else if(last_op == 'b') {
        last_op = '-';
        op_result = num1 - num2;
    } else if(last_op == 'c') {
        last_op = '*';
        op_result = num1 * num2;
    }
    string result = "";
    result = result + to_string(num1) + last_op + to_string(num2) + "=" + to_string(op_result);
    cout << result << endl << result.length() << endl;
}
int main(){
    int i, start = 0;
    cin >> i;
    string input;
    char last_op;
    for(int j = 0;j < i;j++) {
        cin >> input;
        if(input[0] == 'a' || input[0] == 'b' || input[0] == 'c') {
            last_op = input[0];
            main1(last_op, 1, "");
        } else {
            main1(last_op, 2, input);
        }
    }
    return 0;
}