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
    vector<int> doctors(n);
    for(int i = 0;i < n;i++){
        scanf("%d", &doctors[i]);
    }

    int min = 2147483647, min_id = 0;
    for(int i = 0;i < n;i++)
        if(min > doctors[i]){
            min = doctors[i];
            min_id = i;
        }
    
    cout << min_id + 1 << endl;
    
    return 0;
}