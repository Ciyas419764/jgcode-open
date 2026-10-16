#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

vector<int> find_sub_str(string str, string sub_str){
    if(sub_str.length() == 0 || str.length() == 0) return vector<int> (0);
    vector<int> out;
    for(int i = 0;i < (int) str.length() - (int) sub_str.length() + 1;i++){
        if(str.substr(i, sub_str.length()) == sub_str) out.push_back(i);
    }
    return out;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if(find_sub_str(s2, s1).size() != 0) cout << s1 << " is substring of " << s2 << endl;
    else if(find_sub_str(s1, s2).size() != 0) cout << s2 << " is substring of " << s1 << endl;
    else cout << "No substring" << endl;
    
    return 0;
}