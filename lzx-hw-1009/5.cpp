#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;
int main(){
    int n;
    cin >> n;

    vector<double> data(0);
    double temp;
    for(int i = 0;i < n;i++){
        cin >> temp;
        data.push_back(temp);
    }

    double sum = 0, avg;
    for(int i = 0;i < n;i++){
        sum += data[i];
    }
    avg = sum / n;

    double sigma2 = 0;
    double sigma = 0;
    for(int i = 0;i < n;i++){
        sigma2 += (data[i] - avg) * (data[i] - avg);
    }
    sigma = sqrt(sigma2 / n);

    printf("%.4f %.4f", avg, sigma);

    return 0;
}