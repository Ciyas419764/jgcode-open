#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>

using namespace std;
int main(){
    int day = 0;
    cin >> day;

    if(day == 1 || day == 3 || day == 5){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;

    return 0;
}