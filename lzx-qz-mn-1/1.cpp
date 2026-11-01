#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string str;
    
    while(getline(cin, str)){
        int num = stoi(str);
        string new_str = to_string(num);
        cout << new_str.length() << endl;
    }
    
    return 0;
}
