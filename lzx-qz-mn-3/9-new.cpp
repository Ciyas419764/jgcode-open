#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> pre(n + 1, 0);
    for(int i = 0; i < n; i++){
        pre[i + 1] = pre[i] + a[i];
    }

    for(int i = n - 1; i >= 0; i--){
        long long L = n - i - 1;              // 后缀长度
        long long S = pre[i + 1] + L * a[i];  // 把后缀削到 a[i] 后的总和

        // 合法条件：a[i] <= S / k  <=>  k * a[i] <= S
        if((long long)k * a[i] <= S){
            long long P = pre[i + 1];         // 前 i+1 个原值之和
            double T = (double)P / (k - L);
            printf("%.3lf\n", T);
            return 0;
        }
    }

    return 0;
}