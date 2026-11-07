// 啤酒厂选址——O(n)级别优化

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;

long long qzh[10001] = {0}; // distance的前缀和，下标10000是L, 下标10000以下是对应居民点到原点的距离
long long beer_qzh[10001] = {0}; // weight的前缀和
int jmd_beer[10000] = {0};
int jmd_distance[10000] = {0};
long long L = 0; // 圆环总长

void calculate_qzh(int n){
    long long sum = 0;
    for(int i = 0;i < n;i++){
        sum += jmd_distance[i];
        qzh[i + 1] = sum;
    }
    L = sum;
    sum = 0;
    for(int i = 0;i < n;i++){
        sum += jmd_beer[i];
        beer_qzh[i + 1] = sum;
    }
    return;
}

int calculate_distance(int jmd_a, int jmd_b, int n){
    int jmd_min = min(jmd_a, jmd_b);
    int jmd_max = max(jmd_a, jmd_b);
    long long a = qzh[jmd_max] - qzh[jmd_min];
    return min(a, L - a);
}

int calculate_distance_ssz(int jmd_a, int jmd_b, int n){
    if(jmd_b >= jmd_a) return qzh[jmd_b] - qzh[jmd_a];
    else return L - qzh[jmd_a] + qzh[jmd_b];
}

long long calculate_sigma_weight(int jmd_a, int jmd_b, int n){ // 从a居民点到b居民点，顺时针之和，包括端点
    if (jmd_a <= jmd_b)
        return beer_qzh[jmd_b + 1] - beer_qzh[jmd_a];
    else
        return beer_qzh[n] - beer_qzh[jmd_a] + beer_qzh[jmd_b + 1];
}

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d", &jmd_beer[i]);
        scanf("%d", & jmd_distance[i]);
    }

    calculate_qzh(n);

    long long current_price = 0;
    long long min_price = LONG_LONG_MAX;
    int min_idx = 0;
    int left_idx_old, left_idx_new; // 与居民点对位的点位于(left_idx, left_idx + 1]中间

    for(int i = 0;i < n;i++){
        current_price += calculate_distance(0, i, n) * jmd_beer[i];
    }
    if(min_price > current_price){
        min_price = current_price;
        min_idx = 0;
    }
    for(int i = 0;i < n;i++){
        if(calculate_distance_ssz(0, i, n) * 2 < L && calculate_distance_ssz(0, (i + 1) % n, n) * 2 >= L){
            left_idx_old = i;
            break;
        }
    }
    // 现在0号居民点的价格初始化好了

    // 接下来计算1到n号居民点的价格
    for(int i = 1;i < n;i++){
        // 先算线性变化
        current_price += calculate_sigma_weight(left_idx_old + 1, i - 1, n) * calculate_distance(i, i - 1, n);
        current_price -= calculate_sigma_weight(i, left_idx_old, n) * calculate_distance(i, i - 1, n);

        // 更新left_idx_new
        for(int j = left_idx_old;j < left_idx_old + n;j++){
            if(calculate_distance_ssz(i, j % n, n) * 2 < L && calculate_distance_ssz(i, (j + 1) % n, n) * 2 >= L){
                left_idx_new = j % n;
                break;
            }
        }

        // 再算非线性变化，只用算left_idx_old + 1到left_idx_new的
        if (left_idx_new != left_idx_old) {
            int j = (left_idx_old + 1) % n;
            while (true) {
                current_price += 1LL * jmd_beer[j] * (2 * calculate_distance(i, j, n) - L);
                if (j == left_idx_new) break;
                j = (j + 1) % n;
            }
        }
        // 维护left_idx
        left_idx_old = left_idx_new;

        // 更新min
        if(min_price > current_price){
            min_price = current_price;
            min_idx = i;
        }
    }

    cout << min_idx << ',' << min_price << endl;

    return 0;
}