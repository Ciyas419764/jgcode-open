#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

vector<string> split(string str, char ch){
    vector<string> spt_str;
    vector<int> spt_index(1, -1);
    for(int i = 0;i < str.length();i++){
        if(str[i] == ch) spt_index.push_back(i);
    }
    spt_index.push_back(str.length());
    for(int i = 1;i < spt_index.size();i++){
        if(spt_index[i] - spt_index[i - 1] > 1) spt_str.push_back(str.substr(spt_index[i - 1] + 1, spt_index[i] - spt_index[i - 1] - 1));
    }
    return spt_str;
}

int main(){
    int words_count;string enter;
    string s = "", tmp;
    cin >> words_count;
    getline(cin, enter);
    while(getline(cin, tmp)){
        s += tmp;
    }

    auto words = split(s, ' ');



    string line;
    for(int i = 0;i < words.size();i++){
        line += words[i] + " ";
        if(line.length() + ((i != words.size() - 1) ? words[i + 1].length() : 0) > 80){
            line.pop_back();
            cout << line << endl;
            line = "";
        }
    }
    line.pop_back();
    cout << line << endl;
    
    return 0;
}