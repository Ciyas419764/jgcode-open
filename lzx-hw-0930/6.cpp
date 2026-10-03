#include<iostream>
using namespace std;

int main(){
    int year = 0;
    cin >> year;

    if(year % 4 != 0) cout << 'N' << endl;
    else if(year % 100 == 0 && year % 400 != 0) cout << 'N' << endl;
    else if(year % 400 == 0) cout << 'Y' << endl;
    else cout << 'Y' << endl;

    return 0;
}