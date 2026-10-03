#include<iostream>
using namespace std;

int fbnq(int n){
    if(n == 1 || n == 2) return 1;
    else return fbnq(n - 1) + fbnq(n - 2);
}

int main(){
    int n, t;
    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> t;
        cout << fbnq(t) << endl;
    }
    
    return 0;
}