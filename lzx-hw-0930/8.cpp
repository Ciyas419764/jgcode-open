#include<iostream>
using namespace std;

int jc(int n){
    if(n == 0) return 1;
    return n * jc(n - 1);
}

int sum_of_jc(int n){
    if(n == 1) return 1;
    return jc(n) + sum_of_jc(n - 1);
}

int main(){
    int n;
    cin >> n;
    cout << sum_of_jc(n) << endl;
    return 0;
}