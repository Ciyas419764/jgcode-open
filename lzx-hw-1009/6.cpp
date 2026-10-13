#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

bool is_prime(int n){
    bool flag = true;
    for(int i = 2;i < ceil(sqrt(n)) + 1;i++){
        if(n % i == 0){
            flag = false;
            break;
        }
    }
    if(n == 3) return true;
    if(n == 2) return true;
    return flag;
}

int main(){
    int m, k;
    cin >> m >> k;
    vector<int> primes(0);

    int count = 0;
    for(int i = m + 1;;i++){
        if(is_prime(i)){
            primes.push_back(i);
            count++;
        }
        if(count == k) break;
    }

    for(int i = 0;i < primes.size();i++){
        cout << primes[i];
        if(i != primes.size() - 1) cout << " ";
    }
    return 0;
}