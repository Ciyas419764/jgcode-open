#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

string to_upper_case(string str){
    const int delta = 'a' - 'A';
    auto new_str = str;
    for(int i = 0;i < str.length();i++){
        if(str[i] >= 'a') new_str[i] -= delta;
    }
    return new_str;
}

int main(){
    string str;
    for(;;){
        getline(cin, str);
        if(str == "") return 0;
        str = to_upper_case(str);
        int left_index = 0;
        for(int i = 1;i < str.length();i++){
            if(str[i] != str[i - 1]){
                cout << '(' << str[i - 1] << ',' << i - left_index << ')';
                left_index = i;
            }
        }
        cout << '(' << str[str.length() - 1] << ',' << str.length() - left_index << ')' << endl;
    }
    return 0;
}