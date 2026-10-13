#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>

using namespace std;
int main(){
    int max = -2147483648;

    int n, sum = 0;
    cin >> n;

    int temp;
    int count = 1;
    for(int i = 0;i < n;i++){
        cin >> temp;
        sum += temp;
        if(max < temp){
            count = 1;
            max = temp;
        }
        else if(max == temp) count++;
    }

    cout << sum - max * count << endl;

    return 0;
}