#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> patients;
    for(int i = 0;i < n;i++){
        int tmp;scanf("%d", &tmp);
        patients.push_back(tmp);
    }
    sort(patients.begin(), patients.end());

    int patient_idx = 0, count = 0;

    for(int i = 60;i < 180;i++){
        if(patient_idx >= patients.size()) break;
        if(i >= patients[patient_idx]){
            if(i + 10 <= 180){
                patient_idx++;
                i += 10;
                count++;
            }
            else break;
        }
    }

    cout << count << endl;
}