#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

bool is_max_in_row(vector<vector<int>> matrix, int i, int j){
    int max = -2147483648;
    for(int k = 0;k < 5;k++){
        if(matrix[i][k] > max) max = matrix[i][k];
    }
    return matrix[i][j] == max;
}

bool is_min_in_column(vector<vector<int>> matrix, int i, int j){
    int min = +2147483647;
    for(int k = 0;k < 5;k++){
        if(matrix[k][j] < min) min = matrix[k][j];
    }
    return matrix[i][j] == min;
}

int main(){
    vector<vector<int>> matrix(5, vector<int>(5, 0));
    bool flag = false;
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++) scanf("%d", &matrix[i][j]);
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++){
            if(is_max_in_row(matrix, i, j) && is_min_in_column(matrix, i, j)) {
                cout << i + 1 << ' ' << j + 1 << ' ' << matrix[i][j];
                flag = true;
            }
        }
    if(!flag) cout << "not found" << endl;
    
    return 0;
}