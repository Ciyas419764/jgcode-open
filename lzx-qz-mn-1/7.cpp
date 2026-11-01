#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a > b) cout << a - b << endl;
    else{
        int i, tmp_a = a;
        for(i = 1;;i++){
            tmp_a *= 2;
            if(tmp_a > b) break;
        }
        cout << min(i - 1 + b - tmp_a / 2, i + tmp_a - b) << endl;
    }
    return 0;
}