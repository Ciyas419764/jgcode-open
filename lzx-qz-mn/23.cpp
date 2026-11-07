// 跳水比赛

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

int main(){
    int a, b, c, d, e;
    int A, B, C, D, E;

    for(a = 1;a <= 5;a++){
        for(b = 1;b <= 5;b++){
            if(b == a) continue;
            for(c = 1;c <= 5;c++){
                if(c == a || c == b) continue;
                for(d = 1;d <= 5;d++){
                    if(d == a || d == b || d == c) continue;
                    e = 15 - a - b - c - d;
                    A = (b == 2) + (a == 3);
                    B = (b == 2) + (e == 4);
                    C = (c == 1) + (d == 2);
                    D = (c == 5) + (d == 3);
                    E = (e == 4) + (a == 1);
                    if(A == 1 && B == 1 && C == 1 && D == 1 && E == 1) goto success;
                }
            }
        }
    }

    cout << "fuck" << endl;
    return 0;

    success:
        cout << a << endl << b << endl << c << endl << d << endl << e << endl;
    
    return 0;
}