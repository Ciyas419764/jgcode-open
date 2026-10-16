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

    for(int i = 0;i < n;i++){
        scanf("%d", &nums[i]);
    }

    int m, count = 0;
    cin >> m;
    for(int i = 0;i < n;i++){
        if(nums[i] == m) count++;
    }

    cout << count << endl;
    
    return 0;
}