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
    int N;
    cin >> N;
    vector<bool> lamps(N + 1, true);

    for(int i = 1;i <= N;i++){
        for(int j = i;j <= N;j += i){
            lamps[j] = lamps[j] ^ 1;
        }
    }

    string answer = "";
    for(int i = 1;i <= N;i++){
        if(lamps[i]) answer += to_string(i) + " ";
    }

    cout << answer << endl;
    
    return 0;
}