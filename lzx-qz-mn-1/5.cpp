#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

int get_a_return_type(vector<int> strings){
    int max = 0;
    if(strings.size() == 1) return strings[0];
    for(int i = 0;i < strings.size();i++){
        if(max < strings[i]) max = strings[i];
    }
    if(max <= 2) max = 3;
    return max;
}

vector<int> split(string s){
    int left_idx = -1;
    vector<int> out;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '*' || s[i] == '+'){
            if(s[left_idx + 1] == 'c') out.push_back(1);
            else if(s[left_idx + 1] == 'b') out.push_back(2);
            else if(s[left_idx + 1] == 'i') out.push_back(3);
            else if(s[left_idx + 1] == 'l') out.push_back(4);
            else if(s[left_idx + 1] == 'f') out.push_back(5);
            else if(s[left_idx + 1] == 'd') out.push_back(6);
            left_idx = i;
        }
    }
    if(s[left_idx + 1] == 'c') out.push_back(1);
    else if(s[left_idx + 1] == 'b') out.push_back(2);
    else if(s[left_idx + 1] == 'i') out.push_back(3);
    else if(s[left_idx + 1] == 'l') out.push_back(4);
    else if(s[left_idx + 1] == 'f') out.push_back(5);
    else if(s[left_idx + 1] == 'd') out.push_back(6);
    return out;
}

int find_last_comma(string s){
    int last_comma = -1;
    for(int i = 0;i < s.length();i++){
        if(s[i] == ',') last_comma = i;
    }
    return last_comma;
}

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        string str;cin >> str;
        int last = find_last_comma(str);
        auto a = split(str.substr(last + 1, str.size() - last - 1));
        int out = get_a_return_type(a);
        switch (out)
        {
        case 1:
            cout << "char" << endl;
            break;
        case 2:
            cout << "bool" << endl;
            break;
        case 3:
            cout << "int" << endl;
            break;
        case 4:
            cout << "longlong" << endl;
            break;
        case 5:
            cout << "float" << endl;
            break;
        case 6:
            cout << "double" << endl;
            break;
        
        default:
            break;
        }
    }
    return 0;
}