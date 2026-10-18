#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    vector<int> stripped_nums;
    int left_index = -1;
    for(int i = 0;i < s.length();i++){
        if(s[i] < '0' || s[i] > '9'){
            if(left_index < i - 1) stripped_nums.push_back(stoi(s.substr(left_index + 1, i - left_index - 1)));
            left_index = i;
        }
    }
    if(left_index < s.length() - 1) stripped_nums.push_back(stoi(s.substr(left_index + 1, s.length() - left_index - 1)));
    
    sort(stripped_nums.begin(), stripped_nums.end());

    if(stripped_nums.size() == 0){
        cout << "0" << endl;
        return 0;
    }

    string out = "";
    for(int i = 0;i < stripped_nums.size();i++){
        out += to_string(stripped_nums[i]) + ",";
    }
    out.pop_back();

    cout << out << endl;
    
    return 0;
}