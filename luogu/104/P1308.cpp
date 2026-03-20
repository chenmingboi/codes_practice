#include<bits/stdc++.h>
using namespace std;


//题解中第二个比较简单，通过给word和sentence前后个插入一个空格，这样就可以省去第一个for循环进行第二个时的if条件判断
int main(){
    string word;
    cin >> word;
    cin.ignore();//吃掉残留的换行符
    string sentence;
    getline(cin, sentence);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);//将sentence全部转化为小写
    int len_word = word.length(), len_sen = sentence.length(), result = 0, pos = INT_MAX;
    for(int i = 0;i <= len_sen-len_word;i++){
        bool flag = true;
        //判断当前i到i+len_word是否是一个完整的单词
        //可以通过给s开头和结尾各插入一个空格，来简化判断条件，同时i要从1开始到len_sen-len_word-1
        if((i == 0 || sentence[i-1] == ' ') && (i == len_sen-len_word || sentence[i+len_word] == ' ')) {
            for(int j = i;j < i + len_word;j++) {
                if(word[j-i] == sentence[j]) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                result++;
                pos = min(pos, i);
            }
        
        }
    }
    if(result) {
        cout << result << ' ' << pos;
    } else {
        cout << -1;
    }
    return 0;
}