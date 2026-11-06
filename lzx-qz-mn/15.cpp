#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

bool compare(vector<vector<char>> mtx_a, vector<vector<char>> mtx_b){
    for(int i = 0;i < mtx_a.size();i++)
        for(int j = 0;j < mtx_a[i].size();j++)
            if(mtx_a[i][j] != mtx_b[i][j]) return false;
    return true;
}

vector<vector<char>> s90(vector<vector<char>> a){
    int n = a.size();
    vector<vector<char>> new_matrix(a.size(), vector<char>(a.size()));
    for(int i = 0;i < a.size();i++)
        for(int j = 0;j < a.size();j++){
            new_matrix[i][j] = a[n - j - 1][i];
        }
    return new_matrix;
}

vector<vector<char>> n90(vector<vector<char>> a){
    int n = a.size();
    vector<vector<char>> new_matrix(a.size(), vector<char>(a.size()));
    for(int i = 0;i < a.size();i++)
        for(int j = 0;j < a.size();j++){
            new_matrix[i][j] = a[j][n - i - 1];
        }
    return new_matrix;
}

vector<vector<char>> fs(vector<vector<char>> a){
    int n = a.size();
    vector<vector<char>> new_matrix(a.size(), vector<char>(a.size()));
    for(int i = 0;i < a.size();i++)
        for(int j = 0;j < a.size();j++){
            new_matrix[i][j] = a[n - i - 1][n - j - 1];
        }
    return new_matrix;
}

int main(){
    int n;cin >> n;
    vector<vector<char>> matrix_origin(n, vector<char>(n));
    vector<vector<char>> matrix_trans(n, vector<char>(n));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            char tmp;
            cin >> tmp;
            matrix_origin[i][j] = tmp;
        }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            char tmp;
            cin >> tmp;
            matrix_trans[i][j] = tmp;
        }
    
    if(compare(s90(matrix_origin), matrix_trans)) cout << 1 << endl;
    else if(compare(n90(matrix_origin), matrix_trans)) cout << 2 << endl;
    else if(compare(fs(matrix_origin), matrix_trans)) cout << 3 << endl;
    else if(compare(matrix_origin, matrix_trans)) cout << 4 << endl;
    else cout << 5 << endl;
    return 0;
}