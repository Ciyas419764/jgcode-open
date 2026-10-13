#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

// bool is_zero(vector<int> vec){
//     return vec[0] == 0 && vec[1] == 0;
// }

// int cc(vector<int> vec1, vector<int> vec2){
//     return vec1[0] * vec2[1] - vec1[1] * vec2[0];
// }

// bool is_tsbx_xh(vector<int> d_a, vector<int> d_b, vector<int> d_c){
//     vector<int> b = {d_b[0] + d_a[0], d_b[1] + d_a[1]};
//     vector<int> c = {d_c[0] + b[0], d_c[1] + b[1]};
//     int flag1 = cc(d_a, b);
//     int flag2 = cc(d_a, c);
//     return cc(d_a, b) > 0 && cc(d_a, c) > 0;
// }

// bool is_tsbx(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y, int d_x, int d_y){
//     vector<int> d_a = {b_x - a_x, b_y - a_y};
//     vector<int> d_b = {c_x - b_x, c_y - b_y};
//     vector<int> d_c = {d_x - c_x, d_y - c_y};
//     vector<int> d_d = {a_x - d_x, a_y - d_y};
//     if(is_zero(d_a) || is_zero(d_b) || is_zero(d_c) || is_zero(d_b)) return false;

//     return is_tsbx_xh(d_a, d_b, d_c) && is_tsbx_xh(d_b, d_c, d_d) && is_tsbx_xh(d_c, d_d, d_a) && is_tsbx_xh(d_d, d_a, d_b);
// }

int main(){

    int points[8] = {0};

    int results[8] = {0};
    
    for(int i = 0;cin >> points[i % 8];i++){
        if(i % 8 == 7 && i != 0){
            for(int j = 0;j < 4;j++){
                int dx = points[(j * 2 + 2) % 8] - points[(j * 2) % 8];
                int dy = points[(j * 2 + 3) % 8] - points[(j * 2 + 1) % 8];
                int v1_x = points[(j * 2 + 4) % 8] - points[(j * 2) % 8];
                int v1_y = points[(j * 2 + 5) % 8] - points[(j * 2 + 1) % 8];
                int v2_x = points[(j * 2 + 6) % 8] - points[(j * 2) % 8];
                int v2_y = points[(j * 2 + 7) % 8] - points[(j * 2) % 8];
                results[j * 2] = dx * v1_y - v1_x * dy;
                results[j * 2 + 1] = dx * v1_y - v1_x * dy;
            }
            bool flag = true;
            for(int j = 1;j < 8;j++){
                if(results[j] == 0){
                    flag = false;
                    break;
                }
                else if(results[j] / abs(results[j]) != results[j - 1] / abs(results[j - 1])){
                    flag = false;
                    break;
                }
            }
            if(flag) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    
    return 0;
}