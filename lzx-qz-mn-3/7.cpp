#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

int get_truenum(int num){
    while(num % 5 == 0) num /= 5;
    while(num % 2 == 0) num /= 2;
    return num;
}

int find_min_rev(int mod_k){
    int i;
    int ten_pow_i = 1;
    for(i = 1;;i++){
        ten_pow_i = (ten_pow_i * 10) % mod_k;
        if(ten_pow_i == 1) return i;
    }
}

int gcd(int a, int b){
    if(a > b) return gcd(a - b, b);
    else if(a < b) return gcd(a, b - a);
    else return a;
}

int main(){
    int a, b;
    cin >> a >> b;
    int gcd_i = gcd(a, b);
    a /= gcd_i;
    b /= gcd_i;
    int truenum = get_truenum(b);
    if(truenum == 1){
        cout << "0" << endl;
    }
    else{
        cout << find_min_rev(truenum) << endl;
    }
    return 0;
}