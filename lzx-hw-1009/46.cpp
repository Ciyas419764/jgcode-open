#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

bool is_valid(int a, int b, int c, int d, int e){
    int cnt_a = (b == 2) + (a == 3);
    int cnt_b = (b == 2) + (e == 4);
    int cnt_c = (c == 1) + (d == 2);
    int cnt_d = (c == 5) + (d == 3);
    int cnt_e = (e == 4) + (a == 1);
    if(cnt_a == 1 && cnt_b == 1 && cnt_c == 1 && cnt_d == 1 && cnt_e == 1) return true;
    return false;
}

int main(){
    int a, b, c, d, e;

    for(int a = 1;a <= 5;a++){
        for(int b = 1;b <= 5;b++){
            if(b == a) continue;
            for(int c = 1;c <= 5;c++){
                if(c == a || c == b) continue;
                for(int d = 1;d <= 5;d++){
                    if(d != a && d != b && d != c){
                        e = 15 - a - b - c - d;
                        if(is_valid(a, b, c, d, e)) cout << a << endl << b << endl << c << endl << d << endl << e << endl;
                    }
                }
            }
        }
    }
    
    return 0;
}