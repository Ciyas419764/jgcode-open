// 单词倒排

#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

vector<string> split(string a, char ch){
    int idx = -1;
    vector<string> out_str;
    for(int i = 0;i < a.length();i++){
        if(a[i] == ch){
            out_str.push_back(a.substr(idx + 1, i - idx - 1));
            idx = i;
        }
    }
    out_str.push_back(a.substr(idx + 1, a.length() - idx - 1));
    return out_str;
}

int main(){
    string s;getline(cin, s);
    auto splitted = split(s, ' ');

    string out = "";
    for(int i = splitted.size() - 1;i >= 0;i--){
        out += splitted[i] + " ";
    }

    out.pop_back();
    cout << out << endl;

    return 0;
}