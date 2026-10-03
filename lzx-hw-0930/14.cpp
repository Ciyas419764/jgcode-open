#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    double x, a, e;

    cin >> x >> a >> e;

    int N;

    for(N = 0;abs(x / pow(a, N)) >= e;N++){}

    int out = (N - 1 < 0) ? 0 : (N - 1);

    cout << out << endl;

}