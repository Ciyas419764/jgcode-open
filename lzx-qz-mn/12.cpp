#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

struct Patient
{
    int wait;
    int id;
};

bool compare(Patient a, Patient b){
    return a.wait < b.wait;
}


int main(){
    int n;cin >> n;
    vector<Patient> patients(n);
    for(int i = 0;i < n;i++){
        scanf("%d", &patients[i].wait);
        patients[i].id = i + 1;
    }
    sort(patients.begin(), patients.end(), compare);

    int sum = 0;
    for(int i = 0;i < n;i++){
        int wait = 0;
        for(int j = 0;j < i;j++){
            wait += patients[j].wait;
        }
        sum += wait;
    }

    for(int i = 0;i < n - 1;i++){
        cout << patients[i].id << " ";
    }
    cout << patients[n - 1].id << endl;

    printf("%.2f\n", (double) sum / n);
    return 0;
}