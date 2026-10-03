#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    double initial_height = 0;
    cin >> initial_height;

    cout << 3 * initial_height - 2 * initial_height * pow((double) 0.5, 9) << endl;

    printf("%.6f", initial_height * pow((double) 0.5, 10));

    return 0;
}