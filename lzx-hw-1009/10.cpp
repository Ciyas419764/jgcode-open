#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

int sum_of_digits(int num){
    string tmp = to_string(num);
    int sum = 0;
    for(int i = 0;i < tmp.length();i++){
        sum += tmp[i] - '0';
    }

    return sum;
}

int main(){
    const int max = 10000;

    int m, n, k;
    vector<vector<int>> out(max, vector<int>(0));

    char tmp;
    cin >> m >> tmp >> n >> tmp >> k;

    for(int i = m + 1;i < n;i++){
        if(sum_of_digits(i) % k == 0) out[sum_of_digits(i) / k].push_back(i);
    }

    for(int i = 0;i < max;i++){
        if(out[i].size() == 0) continue;
        else{
            for(int j = 0;j < out[i].size() - 1;j++){
                printf("%d,", out[i][j]);
            }
            printf("%d\n", out[i][out[i].size() - 1]);
        }
    }

    return 0;
}