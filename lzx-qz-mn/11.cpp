#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

bool is_r(int year){
    if(year % 4 == 0){
        if(year % 400 == 0) return true;
        if(year % 100 == 0) return false;
        return true;
    }
    else return false;
}

int get_days_of_month(int month, int year){
    switch (month)
    {
    case 1:
        return 31;
    case 2:
        return is_r(year) ? 29 : 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    
    default:
        break;
    }
}

int main(){
    int n;cin >> n;

    for(int i = 0;i < n;i++){
        int year, month1, month2;
        cin >> year >> month1 >> month2;

        int sum_days = 0;
        for(int j = min(month1, month2);j < max(month1, month2);j++){
            sum_days += get_days_of_month(j, year);
        }

        if(sum_days % 7 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}