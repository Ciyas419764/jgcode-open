#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

int methods_recursive(int a){
    if(a == 1) return 0;
    else if(a == 2) return 1;
    else if(a == 3) return 1;
    else if(a == 4) return 2;
    else if(a % 2 == 0){
        return (methods_recursive(a - 4) + 2 * methods_recursive(a - 3) + methods_recursive(a - 2)) % 10000;
    }
    else{
        return (methods_recursive(a - 3) + methods_recursive(a - 2)) % 10000;
    }
    return 0;
}

int main(){
    int n;cin >> n;

    cout << methods_recursive(2 * n) << endl;

    return 0;
}