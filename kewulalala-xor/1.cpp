#include<stdio.h>
#include<iostream>

using namespace std;

const int MAX = 1e5 + 10;

unsigned int nums[MAX] = {0};
unsigned int nums_xor_odd[MAX] = {0};
unsigned int nums_xor_even[MAX] = {0};

void calculate_xor_odd(int N, int abstract){
    int sum = 0;
    for(int i = 1;i < N;i++){
        sum ^= abstract ^ nums[i];
        nums_xor_odd[i] = sum;
    }
    return;
}

void calculate_xor_even(int N){
    int sum = 0;
    for(int i = 1;i < N;i++){
        sum ^= nums[i];
        nums_xor_even[i] = sum;
    }
}

int main(){
    int N;
    cin >> N;

    int abstract_xor = 0;

    for(int i = 0;i < N;i++){
        scanf("%d", &nums[i]);
        abstract_xor ^= nums[i];
    }

    if((N % 2 == 0) && (abstract_xor != 0)){
        cout << "-1" << endl;
        return 0;
    }

    if(N % 2 != 0){
        int sum = 0;
        int t1 = 0;
        int count = 0;
        calculate_xor_odd(N, abstract_xor);

        for(int i = 0;i < 16;i++){
            count = 0;
            for(int j = 0;j < N;j++){
                count += (nums_xor_odd[j] & (1 << i)) >> i;
            }
            t1 += (count * 2 > N) ? (1 << i) : 0;
        }

        for(int i = 0;i < N;i++){
            sum += nums_xor_odd[i] ^ t1;
        }

        cout << sum << endl;
    }

    else{
        int sum = 0;
        int t1 = 0, et = 0;
        int count = 0;
        calculate_xor_even(N);


        // search (2n-1)
        for(int i = 0;i < 16;i++){
            count = 0;
            for(int j = 0;j < N;j += 2){
                count += (nums_xor_even[j] & (1 << i)) >> i;
            }
            t1 += (count * 4 > N) ? (1 << i) : 0;
        }

        //search (2n)
        for(int i = 0;i < 16;i++){
            count = 0;
            for(int j = 1;j < N;j += 2){
                count += (nums_xor_even[j] & (1 << i)) >> i;
            }
            et += (count * 4 > N) ? (1 << i) : 0;
        }

        for(int i = 0;i < N;i++){
            sum += (i % 2 == 0) ? nums_xor_even[i] ^ t1 : nums_xor_even[i] ^ et;
        }

        cout << sum << endl;
    }

}