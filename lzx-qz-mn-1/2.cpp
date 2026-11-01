#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int m, n, k;
    cin >> n >> m >> k;
    
    vector<vector<bool>> data(k, vector<bool>(m, false));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int tmp_day;scanf("%d", &tmp_day);
            data[tmp_day - 1][j] = true;
        }
    }

    vector<int> count(k, 0);
    string out = "";
    for(int i = 0;i < k;i++){
        for(int j = 0;j < m;j++){
            count[i] += data[i][j];
        }
        out += to_string(count[i]) + " ";
    }
    out.pop_back();
    cout << out;

    return 0;
}