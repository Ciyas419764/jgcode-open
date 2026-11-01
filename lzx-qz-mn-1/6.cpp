#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        int m;scanf("%d", &m);
        vector<int> pl(m);
        for(int j = 0;j < m;j++){
            scanf("%d", &pl[j]);
        }
        if(m == 1){
            cout << 0 << endl;
            continue;
        }
        if(m == 2){
            cout << 1 << endl;
            continue;
        }
        int count = 0;
        for(int j = 1;j <= m - 1;j++){
            vector<int> new_pl = pl;
            sort(new_pl.begin(), new_pl.begin() + j);
            sort(new_pl.begin() + j, new_pl.end());
            bool flag1 = true, flag2 = true;;
            if(j == 1 || j == 2) flag1 = true;
            else{
                int c = new_pl[1] - new_pl[0];
                for(int k = 1;k < j - 1;k++){
                    if(new_pl[k + 1] - new_pl[k] != c){
                        flag1 = false;
                        break;
                    }
                }
            }
            if(m - j == 1 || m - j == 2) flag2 = true;
            else{
                int c = new_pl[j + 1] - new_pl[j];
                for(int k = j + 1;k < new_pl.size() - 1;k++){
                    if(new_pl[k + 1] - new_pl[k] != c){
                        flag2 = false;
                        break;
                    }
                }
            }
            if(flag1 && flag2) count++;
        }
        cout << count << endl;
    }
    return 0;
}