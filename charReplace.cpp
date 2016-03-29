#include <iostream>
#include <vector>
using namespace std;

int num(string &s,int len, int index, char ch){
    int total = 0;
    vector<int> tmp1, tmp2;
    int cnt = 0;
    s[index-1] = ch;
    // find all '.' index
    for (int i = 0; i < len; ++i) {
        if(s[i] == '.') {
            tmp1.push_back(i);
        }
    }
    // find -1 to count the continuing '.'
    for(unsigned int j = 0; j < tmp1.size()-1; j++){
        int t = j;
        int count = 0;
        while(tmp1[t+1]-tmp1[t] == 1){
            count++;
            t++;
        }
        if(count > 0) {
            tmp2.push_back(count);
            j = t + count - 1; //optimize
        }
    }
    for (auto iter = tmp2.begin(); iter != tmp2.end(); ++iter) {
        total += *iter;
    }
    return total;
}

int main(){
    int n, m, index;
    char ch;
    bool flag = true;
    while(flag == true){
        string s;
        cin>>n>>m;
        if(n == -1)
            break;
        cin>>s;
        for(int i =0;i < m;i++) {
            cin >> index >> ch;
            cout<<num(s, n, index, ch)<<endl;
        }
        n = -1;
    }
}
