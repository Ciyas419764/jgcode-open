#include<iostream>
using namespace std;

int main(){
    int start, end;
    cin >> start >> end;

    int sum=0;

    for(int i = (start % 2) ? start : start + 1;i <= end;i += 2){
        sum += i;
    }

    cout << sum;

    return 0;
}