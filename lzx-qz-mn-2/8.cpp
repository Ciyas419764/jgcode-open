// 啤酒厂选址

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;

long long qzh[10001] = {0};
int jmd_beer[10000] = {0};
int jmd_distance[10000] = {0};

void calculate_qzh(int n){
    long long sum = 0;
    for(int i = 0;i < n;i++){
        sum += jmd_distance[i];
        qzh[i + 1] = sum;
    }
    return;
}

int calculate_distance(int jmd_a, int jmd_b, int n){
    int jmd_min = min(jmd_a, jmd_b);
    int jmd_max = max(jmd_a, jmd_b);
    return min(qzh[jmd_max] - qzh[jmd_min], qzh[n] - qzh[jmd_max] + qzh[jmd_min]);
}

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d", &jmd_beer[i]);
        scanf("%d", & jmd_distance[i]);
    }

    calculate_qzh(n);

    long long min = LONG_LONG_MAX;
    int min_idx = 0;

    for(int i = 0;i < n;i++){ // 枚举酒厂地址
        long long sum = 0;
        for(int j = 0;j < n;j++){
            sum += calculate_distance(i, j, n) * jmd_beer[j];
        }
        if(sum < min){
            min = sum;
            min_idx = i;
        }
    }

    cout << min_idx << ',' << min << endl;
    return 0;
}