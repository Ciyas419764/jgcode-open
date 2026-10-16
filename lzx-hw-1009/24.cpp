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
    char ch;
    vector<int> numbers;
    int tmp;

    for(int i = 0;i < n;i++){
        numbers.clear();
        vector<int> bucket(151, 0);
        for(int j = 0;;j++){
            scanf("%d", &tmp);
            ch = getchar();
            numbers.push_back(tmp);
            bucket[tmp]++;
            if(ch == '\n') break;
        }
        vector<int> numbers_copy = numbers;
        sort(numbers.begin(), numbers.end());

        bool flag = false;
        if(numbers[0] == numbers[numbers.size() - 1]) {
            cout << "mode=NO" << ',';
            flag = true;
        }

        if(!flag){
            int max = 0;
            int mode = 0;
            for(int i = 0;i < numbers_copy.size();i++){
                if(bucket[numbers_copy[i]] > max){
                    max = bucket[numbers_copy[i]];
                    mode = numbers_copy[i];
                }
            }
            cout << "mode=" << mode << ',';
        }

        if(numbers.size() % 2 == 0){
            int median_1 = numbers[numbers.size() / 2 - 1];
            int median_2 = numbers[numbers.size() / 2];
            cout << "median=(" << median_1 << '+' << median_2 << ")/2" << endl;
        }
        else{
            cout << "median=" << numbers[numbers.size() / 2] << endl;
        }
    }
    
    return 0;
}