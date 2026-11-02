#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

int get_nxs(string a){
    int count = 0;
    for(int i = 0;i < a.length() - 1;i++){
        for(int j = i;j < a.length();j++){
            if(a[i] > a[j]) count++;
        }
    }
    return count;
}

bool compare_sequence(string a, string b){
    return get_nxs(a) < get_nxs(b);
}

int main(){
    int n, m;
    cin >> n >> m;
    string null;getline(cin, null);
    vector<string> strings(m);
    for(int i = 0;i < m;i++){
        getline(cin, strings[i]);
    }
    sort(strings.begin(), strings.end(), compare_sequence);

    for(int i = 0;i < m;i++){
        cout << strings[i] << endl;
    }
    return 0;
}