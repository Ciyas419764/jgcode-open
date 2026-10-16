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
    for(int i = 0;i < n;i++){
        string str = "";
        vector<int> bucket(26);
        cin >> str;
        for(int j = 0;j < str.length();j++) bucket[str[j] - 'a']++;
        int max = 0;
        char ch;
        for(int j = 0;j < bucket.size();j++){
            if(max < bucket[j]){
                max = bucket[j];
                ch = j + 'a';
            }
        }
        cout << ch << " " << max << endl;
    }
    
    return 0;
}