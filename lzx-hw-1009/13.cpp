#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>

using namespace std;
int main(){
    int n;
    cin >> n;

    vector<bool> is_prime(n, true);

    for(int i = 2;i < ceil(sqrt(n)) + 1;i++){
        for(int j = 2 * i - 1;j < is_prime.size();j += i){
            is_prime[j] = false;
        }
    }

    int count = 0;
    for(int i = 1;i < is_prime.size();i++){
        if(is_prime[i]) count++;
    }

    cout << count << endl;
    
    return 0;
}