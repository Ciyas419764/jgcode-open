#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    for(int i = 0;i <= a;i++){
        if(i * 2 + (a - i) * 4 == b){
            cout << i << " " << a - i << endl;
            return 0;
        }
    }
}