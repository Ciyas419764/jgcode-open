#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include <algorithm>
using namespace std;

void print(vector<int> array){
    int a, b, c;

    a = (array[1] > array[0]) + (array[2] == array[0]);
    b = (array[0] > array[1]) + (array[0] > array[2]);
    c = (array[2] > array[1]) + (array[1] > array[0]);
    
    if(a + array[0] == 3 && b + array[1] == 3 && c + array[2] == 3){
        for(int i = 1;i <= 3;i++){
            if(array[0] == i) cout << 'A';
            if(array[1] == i) cout << 'B';
            if(array[2] == i) cout << 'C';
        }
    }
    else{
        return;
    }
}

void qpl(vector<int*> prefix_pointer_array, vector<int> array){
    if(array.size() == 1){
        vector<int> new_array(prefix_pointer_array.size() + array.size(), 0);
        for(int i = 0;i < prefix_pointer_array.size();i++) new_array[i] = *prefix_pointer_array[i];
        for(int i = 0;i < array.size();i++) new_array[i + prefix_pointer_array.size()] = array[i];
        print(new_array);
    }
    else{
        vector<int> new_array(array.size() - 1, 0);
        vector<int*> new_prefix_pointer_array(prefix_pointer_array.size() + 1, 0);
        for(int i = 0;i < array.size();i++){
            copy_n(prefix_pointer_array.begin(), prefix_pointer_array.size(), new_prefix_pointer_array.begin());
            new_prefix_pointer_array[new_prefix_pointer_array.size() - 1] = &array[i];
            new_array = array;
            new_array.erase(new_array.begin() + i);
            qpl(new_prefix_pointer_array, new_array);
        }
    }
}

int main(){
    vector<int*> test_prefix(0);
    vector<int> test_nums = {1, 2, 3};

    qpl(test_prefix, test_nums);

    return 0;
}