#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

double get_next(double last, double n){
    return last - (last * last - n) / (2 * last);
}

int main(){
    double n = 0;
    double last;
    int i;
    while(cin >> n){
        last = 1;
        for(i = 1;;i++){
            if(abs(last - sqrt(n)) < 1e-6) break;
            last = get_next(last, n);
        }
        printf("%d %.2f\n", i, last);
    }

    return 0;
}