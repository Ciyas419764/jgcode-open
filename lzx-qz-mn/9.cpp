#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

vector<int> find_char_in_string(string str, char ch){
    vector<int> out;
    for(int i = 0;i < str.length();i++){
        if(str[i] == ch) out.push_back(i);
    }
    return out;
}

int main(){
    int n;cin >> n;
    string null;getline(cin, null);

    for(int i = 0;i < n;i++){
        string input;getline(cin, input);
        auto maohao = find_char_in_string(input, ':');

        string jx = input.substr(0, maohao[0]);
        string full = input.substr(maohao[0] + 1, input.length() - maohao[0] - 1);

        if(jx.length() >= full.length()){
            cout << "NO" << endl;
            continue;
        }

        vector<vector<int>> searched_chars(jx.length(), vector<int>());

        for(int i = 0;i < jx.length();i++){
            searched_chars[i] = find_char_in_string(full, jx[i]);
        }

        int idx = -1;bool flag = true;
        for(int i = 0;i < searched_chars.size();i++){
            for(int j = 0;;j++){
                if(j >= searched_chars[i].size()){
                    flag = false;
                    goto finish;
                }
                if(searched_chars[i][j] > idx){
                    idx = searched_chars[i][j];
                    break;
                }
            }
        }

        finish:
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;

    }
    return 0;
}