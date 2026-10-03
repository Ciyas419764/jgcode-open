#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n;
    double sum = 0;
    const double one = 1;

    cin >> n;
    
    for(int i = 1;i <= n;i++){
        sum += one / i;
    }

    printf("%.9f", sum);

    return 0;
}