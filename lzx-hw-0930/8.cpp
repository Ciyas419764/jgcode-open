#include<iostream>
using namespace std;

int main(){
    int weights[4] = {0};

    for(int i = 1;i <= 5;i++)
        for(int j = 1;j <= 5;j++)
            for(int k = 1;k <= 5;k++)
                for(int l = 1;l <= 5;l++){
                    if(i + j == k + l && i + l > j + k && i + k < j){
                        weights[0] = i;weights[1] = j;weights[2] = k;weights[3] = l;
                        break;
                    }
                }
    
    for(int i = 5;i >= 1;i--){
        for(int j = 0;j < 4;j++){
            if(weights[j] == i){
                switch (j)
                {
                case 0:
                    cout << "z ";
                    break;
                case 1:
                    cout << "q ";
                    break;
                case 2:
                    cout << "s ";
                    break;
                case 3:
                    cout << "l ";
                    break;
                }
                cout << i * 10 << endl;
            }
        }
    }
}