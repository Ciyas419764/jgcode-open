#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

bool is_hw(string str){
    for(int i = 0;i <= str.length() / 2 + 1;i++){
        if(str[i] != str[str.length() - 1 - i]) return false;
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    if(is_hw(str)) cout << "yes" << endl;
    else cout << "no" << endl;
    
    return 0;
}