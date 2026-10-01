#include<stdio.h>
#include<iostream>

using namespace std;

const int MAX = 1e5 + 10;

int nums[MAX] = {0};
int nums_temp[MAX] = {0};


int main(){
    int N;
    cin >> N;

    int abstract_xor = 0;

    for(int i = 0;i < N;i++){
        scanf("%d", &nums[i]);
        abstract_xor ^= nums[i];
    }

    int sum = 0;
    bool flag_mod_2 = 0;

    if(N % 2 == 0 && abstract_xor != 0){
        cout << "-1" << endl;
        return 0;
    }
    else if(N % 2 == 0) flag_mod_2 = true;
    else flag_mod_2 = false;

    int temp = 0;
    int out_num = 0;
    int min_sum = 2147483647;

    for(int i = 0;i < N;i++){
        sum = 0;
        out_num = flag_mod_2 ? nums[i] : abstract_xor;
        temp = nums[(i + 1) % N];
        for(int j = i;j < N + i - 1;j++){
            sum += out_num ^ temp;
            temp = nums[(j + 2) % N] ^ out_num ^ temp;
        }
        if(sum < min_sum) min_sum = sum;
        // cout << sum << endl;
    }
    cout << min_sum << endl;

    return 0;
}