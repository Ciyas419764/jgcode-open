#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

bool is_left_upper_zero(vector<vector<int>> matrix, int x, int y){
    if(matrix[x][y] != 0) return false;
    
    for(int i = x - 1;i >= 0;i--){
        if(matrix[i][y] == 0) return false;
    }

    for(int i = y - 1;i >= 0;i--){
        if(matrix[x][i] == 0) return false;
    }

    return true;
}

bool is_right_down_zero(vector<vector<int>> matrix, int x, int y){
    if(matrix[x][y] != 0) return false;
    
    for(int i = x + 1;i <= matrix.size() - 1;i++){
        if(matrix[i][y] == 0) return false;
    }

    for(int i = y + 1;i <= matrix[0].size() - 1;i++){
        if(matrix[x][i] == 0) return false;
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    bool flag = false;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) scanf("%d", &matrix[i][j]);

    int lux = 0, luy = 0;
    int rdx = 0, rdy = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(is_left_upper_zero(matrix, i, j)){
                lux = i;
                luy = j;
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(is_right_down_zero(matrix, i, j)){
                rdx = i;
                rdy = j;
            }
        }
    }

    cout << (rdy - luy - 1) * (rdx - lux - 1) << endl;
    
    return 0;
}