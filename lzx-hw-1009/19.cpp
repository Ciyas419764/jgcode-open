#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> odds;

    for(int i = 0;i < n;i++) scanf("%d", &nums[i]);

    for(int i = 0;i < n;i++) if(nums[i] % 2 == 1) odds.push_back(nums[i]);
    
    sort(odds.begin(),odds.end());

    string out = "";

    for(int i = 0;i < odds.size();i++){
        out += to_string(odds[i]) + ",";
    }

    out.pop_back();
    
    cout << out;

    return 0;
}