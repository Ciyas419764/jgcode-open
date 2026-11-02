#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

vector<int> search_char(vector<vector<char>> card, char ch){
    vector<int> out;
    for(int i = 0;i < card[0].size();i++){
        for(int j = 0;j < card.size();j++){
            if(card[j][i] == ch){
                out.push_back(i);
                break;
            }
        }
    }
    return out;
}

int main(){
    int t;cin >> t;
    string null;getline(cin, null);
    for(int i = 0;i < t;i++){
        int n, m;cin >> n >> m;
        char nul;
        getline(cin, null);
        vector<vector<char>> card(n, vector<char>(m));
        for(int i = 0;i < n;i++)
            for(int j = 0;j <= m;j++){
                if(j != m) scanf("%c", &card[i][j]);
                else scanf("%c", &nul);
            }
        auto v_in_line = search_char(card, 'v');
        auto i_in_line = search_char(card, 'i');
        auto k_in_line = search_char(card, 'k');
        auto a_in_line = search_char(card, 'a');
        if((v_in_line.size() == 0) || (i_in_line.size() == 0) || (k_in_line.size() == 0) || (a_in_line.size() == 0) ){
            cout << "NO" << endl;
            continue;
        }
        bool flag = false;
        for(int i = 0;i < i_in_line.size();i++){
            if(i_in_line[i] > v_in_line[0]){
                for(int j = 0;j < k_in_line.size();j++){
                    if(k_in_line[j] > i_in_line[i]){
                        for(int k = 0;k < a_in_line.size();k++){
                            if(a_in_line[k] > k_in_line[j]){
                                flag = true;
                                goto done;
                            }
                        }
                    }
                }
            }
        }
        done:
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
    }
    return 0;
}