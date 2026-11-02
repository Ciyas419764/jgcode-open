#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    int n;cin >> n;
    string null;getline(cin, null);
    for(int i = 0;i < n;i++){
        string str;getline(cin, str);
        if(!(str[0] >= 'a' && str[0] <= 'z') && !(str[0] >= 'A' && str[0] <= 'Z') && !(str[0] == '_')){
            cout << 0 << endl;
            continue;
        }
        bool flag = false;
        for(int i = 0;i < str.length();i++){
            if(!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9') && !(str[i] == '_')){
                cout << 0 << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << 1 << endl;
    }
    return 0;
}