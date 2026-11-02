#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

string to_lower_case(string a){
    for(int i = 0;i < a.length();i++){
        if(a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
    }
    return a;
}

int main(){
    string s;cin >> s;
    vector<int> bucket(26);
    vector<int> idx(26);
    s = to_lower_case(s);
    for(int i = 0;i < s.length();i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(bucket[s[i] - 'a'] == 0){
                idx[s[i] - 'a'] = i;
            }
            bucket[s[i] - 'a']++;
        }
    }
    for(int i = 0;i < bucket.size();i++){
        if(bucket[i] != 0){
            char ch = 'a' + i;
            cout << ch << ' ' << idx[i] << endl;
        }
    }
}