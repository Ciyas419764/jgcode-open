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
    for(;cin >> n;){
        if(n == 0) break;
        else{
            vector<vector<int>> matrix(n, vector<int>(n, 0));
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++) scanf("%d", &matrix[i][j]);
            vector<int> count_hang(0);
            vector<int> count_lie(0);
            int sum = 0;
            for(int i = 0;i < n;i++){
                sum = 0;
                for(int j = 0;j < n;j++){
                    sum += matrix[i][j];
                }
                if(sum % 2 != 0) count_hang.push_back(i);
            }
            for(int i = 0;i < n;i++){
                sum = 0;
                for(int j = 0;j < n;j++){
                    sum += matrix[j][i];
                }
                if(sum % 2 != 0) count_lie.push_back(i);
            }
            if(count_hang.size() == 0 && count_lie.size() == 0) cout << "OK" << endl;
            else if(count_hang.size() == 1 && count_lie.size() == 1) cout << "Change bit (" << count_hang[0] + 1 << ',' << count_lie[0] + 1 << ')' << endl;
            else cout << "Corrupt" << endl;
        }
    }
    
    return 0;
}