#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

string kg(int n){
    string out = "";
    for(int i = 0;i < n;i++) out += " ";
    return out;
}

int main(){
    string str = "", tmp;
    while(getline(cin, tmp)){
        str += tmp;
    }

    vector<int> bucket(26);
    for(int i = 0;i < str.length();i++){
        if(str[i] >= 'A' && str[i] <= 'Z') bucket[str[i] - 'A']++;
    }

    vector<vector<int>> temp(80, vector<int>());
    for(int i = 80;i > 0;i--){
        for(int j = 0;j < 26;j++){
            if(bucket[j] >= i) temp[i - 1].push_back(j);
        }
    }

    for(int i = 80;i > 0;i--){
        if(temp[i - 1].size() > 0) printf("#");
        int idx = -1;
        for(int j = 0;j < temp[i - 1].size();j++){
            printf(kg(temp[i - 1][j] - idx - 1).c_str());
            printf("*");
            idx = temp[i - 1][j];
        }
        if(temp[i - 1].size() > 0) printf("\n");
    }

    printf("#");
    for(int i = 0;i < 26;i++){
        char ch = i + 'A';
        cout << ch;
    }

    return 0;
}