#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>

using namespace std;
int main(){
    int n;
    cin >> n;

    vector<bool> bucket(101, 1);
    vector<int> nums(n);
    for(int i = 0;i < n;i++){
        scanf("%d", &nums[i]);
    }

    string out = "";
    for(int i = 0;i < n;i++){
        if(bucket[nums[i]]){
            out += to_string(nums[i]) + " ";
            bucket[nums[i]] = false;
        }
    }
    out.pop_back();

    cout << out;

    return 0;
}