#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main(){
    int n = 0;
    scanf("%d", &n);

    vector<int> nums(n);

    int count_1 = 0;
    int count_5 = 0;
    int count_10 = 0;
    
    for(int i = 0;i < n;i++){
        scanf("%d", &nums[i]);
    }

    for(int i = 0;i < n;i++){
        if(nums[i] == 1){
            count_1++;
        }
        else if(nums[i] == 5){
            count_5++;
        }
        else if(nums[i] == 10){
            count_10++;
        }
    }

    printf("%d\n%d\n%d\n", count_1, count_5, count_10);

    return 0;
}