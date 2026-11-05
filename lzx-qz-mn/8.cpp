#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    for(;;){
        int n;cin >> n;
        if(n == 0) break;
        vector<int> tj(n);
        vector<int> qw(n);
        for(int i = 0;i < n;i++) scanf("%d", &tj[i]);
        for(int i = 0;i < n;i++) scanf("%d", &qw[i]);

        sort(tj.begin(), tj.end());sort(qw.begin(), qw.end());

        int max = -2147483648;
        for(int i = 0;i < n;i++){
            int cnt = 0;
            for(int j = 0;j < n;j++){
                cnt += (tj[(i + j) % n] == qw[j]) ? 0 : ((tj[(i + j) % n] > qw[j]) ? 200 : -200);
            }
            if(max < cnt) max = cnt;
        }

        cout << max << endl;
    }
    return 0;
}