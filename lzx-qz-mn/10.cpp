#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    int num;cin >> num;

    vector<bool> sequence; // true -> 2x+2,G; false -> 2x+1, N;

    while(num != 0){
        if(num % 2 == 0){
            num = (num - 2) / 2;
            sequence.push_back(1);
        }
        else{
            num = (num - 1) / 2;
            sequence.push_back(0);
        }
    }
    
    for(int i = sequence.size() - 1;i >= 0;i--){
        if(sequence[i]) printf("G");
        else printf("N");
    }

    return 0;
}