#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>

using namespace std;
int main(){
    int n = 0;
    cin >> n;

    int l, h;
    cin >> l >> h;

    int count = 0;
    int temp = 0;
    for(int i = 0;i < n;i++){
        cin >> temp;
        if(temp >= l && temp <= h) count++;
    }

    cout << count << endl;

    return 0;
}