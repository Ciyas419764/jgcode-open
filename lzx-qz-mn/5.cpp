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
    if(sub_str.length() == 0) return vector<int> (0);
    vector<int> out;
    for(int i = 0;i < (int) str.length() - (int) sub_str.length() + 1;i++){
        if(str.substr(i, sub_str.length()) == sub_str) out.push_back(i);
    }
    return out;
}

int main(){
    string s, w;
    cin >> s >> w;

    auto substr = find_sub_str(w, s);

    cout << substr[0] << endl;
    
    return 0;
}