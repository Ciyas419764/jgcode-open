#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;cin >> n;
    int max = 0;int max_2 = 0;
    vector<int> zg;

    for(int i = 0;i < n;i++){
        int a, b;scanf("%d", &a);scanf("%d", &b);
        zg.push_back(b);
        zg.push_back(a - b);
    }

    sort(zg.begin(), zg.end());

    cout << zg[zg.size() - 1] + zg[zg.size() - 2] << endl;
    return 0;
}