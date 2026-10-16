#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

string append_string(string a, string b){
    string tmp = a;
    for(int i = 0;i < b.length();i++){
        tmp.push_back(b[i]);
    }
    return tmp;
}

int main(){
    int n;
    string a, b;
    a = "114514";
    b = "114514";
    cout << append_string(a, b) << endl;
    return 0;
}