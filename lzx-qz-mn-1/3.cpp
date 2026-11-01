#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

struct Patient
{
    string id;
    int age;
};

bool compare_patient_age(Patient a, Patient b){
    return a.age > b.age;
}

int main(){
    vector<Patient> the_old;
    vector<Patient> the_young;
    int n ;cin >> n;

    for(int i = 0;i < n;i++){
        string tmp_str;int age;
        cin >> tmp_str >> age;
        if(age >= 60) the_old.push_back(Patient{tmp_str, age});
        else if(age < 60) the_young.push_back(Patient{tmp_str, age});
    }

    stable_sort(the_old.begin(), the_old.end(), compare_patient_age);
    
    for(int i = 0;i < the_old.size();i++){
        printf("%s\n", the_old[i].id.c_str());
    }
    for(int i = 0;i < the_young.size();i++){
        printf("%s\n", the_young[i].id.c_str());
    }
    return 0;
}