#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>

using namespace std;
int main(){
    int n, x, y;

    cin >> n >> x >> y;

    int temp = n - ceil(y / (double) x);
    int out = temp < 0 ? 0 : temp;

    cout << out << endl;

    return 0;
}