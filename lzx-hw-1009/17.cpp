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
    int top_k;
    cin >> top_k;

    sort(nums.begin(), nums.end());

    for(int i = n - 1;i > n - 1 - top_k;i--){
        printf("%d\n", nums[i]);
    }
    
    return 0;
}