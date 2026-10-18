#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main(){
    int m;
    cin >> m;
    vector<bool> is_prime(m + 1, true);

    for(int i = 2;i <= ceil(sqrt(m) + 1);i++){
        for(int j = 2 * i;j <= m;j += i){
            is_prime[j] = false;
        }
    }

    for(int i = 3;i <= m / 2;i++){
        if(is_prime[i] && is_prime[m - i]) cout << i << " " << m - i << endl;
    }
    
    return 0;
}