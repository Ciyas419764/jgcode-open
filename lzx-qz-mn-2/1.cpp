#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    string s;
    int num;
    cin >> s >> num;
    if(s == "heitao" && num <= 9 && num >= 2){
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
    return 0;
}
