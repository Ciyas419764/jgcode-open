#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int solders[50000] = {0};

int search_num(int n, int init, int r){
    int cnt = 0, idx = -1, idx2 = -1;
    for(int i = init + 1;i < n;i++) if(solders[i] - solders[init] > r){
        idx = i;
        break;
    }
    if(idx == -1) return 1;
    cnt++;

    for(;;){
        cnt++;
        idx2 = -1;
        // find solder to place stone
        for(int i = idx + 1;;i++){
            if(i >= n) return cnt;
            if(solders[i] - solders[idx] > r){
                idx2 = i;
                break;
            }
        }
        
        // find next idx
        for(int i = idx2;;i++){
            if(i >= n) return cnt;
            if(solders[i] - solders[idx2 - 1] > r){
                idx = i;
                break;
            }
        }
    }
}

int main(){
    for(;;){
        int r, n;
        cin >> r >> n;
        if(r == -1 && n == -1) break;

        for(int i = 0;i < 50000;i++) solders[i] = 0;

        for(int i = 0;i < n;i++) scanf("%d", &solders[i]);

        sort(solders, solders + n);

        int min = 2147483647;
        for(int i = 0;i < n;i++){
            if(solders[i] - solders[0] > r) break;
            if(min > search_num(n, i, r)) min = search_num(n, i, r);
        }
        cout << min << endl;
    }
    return 0;
}