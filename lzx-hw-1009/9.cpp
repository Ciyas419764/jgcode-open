#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

bool is_7_in_num(int num){ 
    string tmp = to_string(num);
    if(num % 7 == 0) return true;
    else if(tmp.find('7') != string::npos) return true;
    return false;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0;i < n;i++) nums[i] = i + 1;
    int current_num = 1;
    int current_pointer = 0;

    while(nums.size() >= 1){
        if(is_7_in_num(current_num)){
            cout << nums[current_pointer] << endl;
            nums.erase(nums.begin() + current_pointer);
        }
        else current_pointer++;
        if(current_pointer == nums.size()) current_pointer = 0; 
        current_num++;
    }
    return 0;
}