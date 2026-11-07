// 判断字符串是否为回文

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

int main(){
    string s;cin >> s;

    for(int i = 0;i < s.length();i++){
        if(s[i] != s[s.length() - i - 1]) goto failed;
    }

    cout << "yes" << endl;
    return 0;

    failed:
        cout << "no" << endl;
    return 0;
}