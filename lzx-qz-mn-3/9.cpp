#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<double> chickens(n);

    for(int i = 0;i < n;i++){double tmp;scanf("%lf", &tmp);chickens[i] = tmp;}

    sort(chickens.begin(), chickens.end());

    double avg = 0;
    for(int i = 0;i < n;i++) avg += chickens[i];
    avg /= n;

    for(int i = n - 1;i >= 0;i--){
        int delta = (i == n - 1) ? 0 : chickens[i + 1] - chickens[i];
        for(int j = i + 1;j < n;j++){
            chickens[j] = chickens[i];
        }
        avg -= (double) (n - i - 1) * delta / n;
        
        bool is_valid = true;
        for(int j = i;j < n;j++){
            if(chickens[j] > avg * n / k){
                is_valid = false;
                break;
            }
        }

        if(is_valid){
            double x = (double) k / (k - n + i + 1) * (avg * n / k - chickens[n - 1]);
            if(x < 0){
                cout << "fuck" << endl;
                return 0;
            }
            else{
                for(int j = i + 1;j < n;j++) chickens[j] += x;
            }
            break;
        }
    }

    double sum = 0;
    for(int i = 0;i < n;i++) sum += chickens[i];

    printf("%.3lf", sum / k);
    
    return 0;
}