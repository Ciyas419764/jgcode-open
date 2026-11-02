#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main(){
    double m;cin >> m;
    double out;
    if(m <= 117.192){
        out = m / 0.4883;
    }
    else if(m <= 203.32){
        out = (m - 117.192) / 0.5383 + 240;
    }
    else{
        out = (m - 203.32) / 0.7883 + 400;
    }
    printf("%.2f", out);
    return 0;
}