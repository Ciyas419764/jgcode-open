#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>

using namespace std;
int main(){
    int L, M;
    cin >> L >> M;
    vector<bool> trees(10001, true);
    int begin, end;

    for(int i = 0;i < M;i++){
        cin >> begin >> end;
        for(int j = begin;j <= end;j++){
            trees[j] = false;
        }
    }

    int count = 0;
    for(int i = 0;i <= L;i++){
        if(trees[i]) count++;
    }

    cout << count << endl;
    
    return 0;
}