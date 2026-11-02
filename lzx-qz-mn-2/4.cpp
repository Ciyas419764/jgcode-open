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
        if(str.length() < 6){
            cout << "Not safe" << endl;
            continue;
        }
        vector<int> symbol_bucket(4);
        for(int i = 0;i < str.length();i++){
            if(str[i] <= '9' && str[i] >= '0') symbol_bucket[0]++;
            else if(str[i] >= 'A' && str[i] <= 'Z') symbol_bucket[1]++;
            else if(str[i] >= 'a' && str[i] <= 'z') symbol_bucket[2]++;
            else symbol_bucket[3]++;
        }
        int count = 0;
        for(int i = 0;i < 4;i++) if(symbol_bucket[i] != 0) count++;
        if(count == 1){
            cout << "Not safe" << endl;
            continue;
        }
        else if(count == 2){
            cout << "Medium safe" << endl;
            continue;
        }
        else{
            cout << "Safe" << endl;
            continue;
        }
    }
    return 0;
}