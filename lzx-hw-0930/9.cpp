#include<iostream>
using namespace std;

int main(){
    int weights[4] = {0};
    bool A, B, C, D;

    for(int j = 1;j <= 4;j++){
        A = (j == 2);
        B = (j == 4);
        C = (j != 3);
        D = (!(j == 4));

        if(A + B + C + D == 1){
            if(A) cout << j << endl << 'A' << endl;
            if(B) cout << j << endl << 'B' << endl;
            if(C) cout << j << endl << 'C' << endl;
            if(D) cout << j << endl << 'D' << endl; 
        }
    }
}