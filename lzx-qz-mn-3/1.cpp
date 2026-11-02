#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    printf("%.2f", a * b / sqrt(a * a + b * b));
    return 0;
}