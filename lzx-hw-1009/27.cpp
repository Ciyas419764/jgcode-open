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
    for(int i = 0;i < str.length() - sub_str.length() + 1;i++){
        if(str.substr(i, sub_str.length()) == sub_str) out.push_back(i);
    }
    return out;
}

int main(){
    string s, s2, s3;
    string input;
    cin >> input;
    auto douhao = find_sub_str(input, ",");
    s = input.substr(0, douhao[0]);
    s2 = input.substr(douhao[0] + 1, douhao[1] - douhao[0] - 1);
    s3 = input.substr(douhao[1] + 1, input.length() - douhao[1] - 1);

    auto s2_in_s = find_sub_str(s, s2);
    auto s3_in_s = find_sub_str(s, s3);

    if(s2_in_s.size() == 0 || s3_in_s.size() == 0){
        cout << "-1" << endl;
    }
    else if(s3_in_s[s3_in_s.size() - 1] - s2_in_s[0] - (int) s2.length() < 0){
        cout << "-1" << endl;
    }
    else{
        cout << s3_in_s[s3_in_s.size() - 1] - s2_in_s[0] - (int) s2.length() << endl;
    }
    
    return 0;
}