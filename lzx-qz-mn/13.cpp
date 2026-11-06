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

int main(){
    int n;cin >> n;
    for(int i = n / 2;i >= 1;i--){
        if(gcd(n, i) == 1){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}