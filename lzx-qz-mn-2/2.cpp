#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double x = 0, y = 0;
    double tmp;
    int i = 0;

    while(cin >> tmp){
        if(i % 2 == 0) x += tmp;
        else y += tmp;
        i++;
    }

    printf("%.4f", sqrt(x * x + y * y));

    return 0;
}