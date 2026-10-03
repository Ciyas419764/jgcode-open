#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    double finance[12] = {0};
    double sum = 0;

    for(int i = 0;i < 12;i++){
        cin >> finance[i];
        sum += finance[i];
    }

    printf("$%.2f", sum / 12);

    return 0;
}