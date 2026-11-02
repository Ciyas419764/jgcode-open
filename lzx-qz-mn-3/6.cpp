#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

const string fgf = "----------------------------------------------------------------";

void process_a_pg(vector<string> lines, bool with_fgf){
    string tmp;
    bool flag = false;
    for(int i = 0;i < lines.size();i++){
        if(lines[i].substr(0, 13) == "[Namespace]-("){
            tmp = lines[i].substr(11, 4);
            lines[i].pop_back();lines[i].pop_back();lines[i].pop_back();lines[i].pop_back();
            flag = true;
            break;
        }
    }
    if(flag = false){
        for(int i = 0;i < lines.size();i++){
            printf("%s\n", lines[i].c_str());
        }
        if(with_fgf) printf("%s\n", fgf.c_str());
        return;
    }
    else{
        for(int i = 0;i < lines.size();i++){
            if(lines[i].substr(0, 13) == "[Requirement]") lines[i] += tmp;
        }
        for(int i = 0;i < lines.size();i++){
            printf("%s\n", lines[i].c_str());
        }
        if(with_fgf) printf("%s\n", fgf.c_str());
        return;
    }
}

int main(){
    string tmp;
    vector<string> s; // s 代表分隔符之前出现的所有字符串
    while(getline(cin, tmp)){
        if(tmp == fgf){
            process_a_pg(s, true);
            s.clear();
        }
        else s.push_back(tmp);
    }
    process_a_pg(s, false);

    return 0;
}