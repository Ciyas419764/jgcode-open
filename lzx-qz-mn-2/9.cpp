#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

const int DIGITS = 220;

// compare a and b, output 1 when a > b, output 0 when a < b, output 2 when a == b
int compare(vector<int> a, vector<int> b){
    for(int i = DIGITS - 1;i >= 0;i--){
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return 0;
    }
    return 2;
}

// output a - b, a must be larger than b
vector<int> jian(vector<int> a, vector<int> b){
    int jinwei = 0;
    vector<int> ans(DIGITS);
    for(int i = 0;i < DIGITS;i++){
        ans[i] = a[i] - b[i] - jinwei;
        if(ans[i] < 0){
            ans[i] += 10;
            jinwei = 1;
        }
        else jinwei = 0;
    }
    return ans;
}

// output a + b
vector<int> jia(vector<int> a, vector<int> b){
    int jinwei = 0;
    vector<int> ans(DIGITS);
    for(int i = 0;i < DIGITS;i++){
        ans[i] = a[i] + b[i] + jinwei;
        if(ans[i] >= 10){
            ans[i] -= 10;
            jinwei = 1;
        }
        else jinwei = 0;
    }
    return ans;
}

// fh is true means positive, else means negetive
void output(vector<int> a, bool fh){
    if(fh == false) cout << '-';
    for(int i = DIGITS - 1;i >= 0;i--){
        if(a[i] != 0){
            for(;i >= 0;i--){
                cout << a[i];
            }
            break;
        }
    }
    cout << endl;
    return;
}

// calculate a - b and output
void minus_string(string a, string b){
    bool fha = true, fhb = true;
    if(a[0] == '-') fha = false;
    if(b[0] == '-') fhb = false;

    vector<int> numA(DIGITS);
    vector<int> numB(DIGITS);

    // fill a into numA
    for(int i = a.length() - 1;i >= 0;i--){
        if(a[i] >= '0' && a[i] <= '9') numA[a.length() - 1 - i] = a[i] - '0';
    }

    // fill b into numB
    for(int i = b.length() - 1;i >= 0;i--){
        if(b[i] >= '0' && b[i] <= '9') numB[b.length() - 1 - i] = b[i] - '0';
    }

    if(fha && fhb){
        int tmp = compare(numA, numB);
        if(tmp == 2){
            cout << 0 << endl;
            return;
        }
        else if(tmp == 1){
            auto ans = jian(numA, numB);
            output(ans, true);
        }
        else if(tmp == 0){
            auto ans = jian(numB, numA);
            output(ans, false);
        }
    }
    else if(fha && !fhb){
        auto ans = jia(numA, numB);
        output(ans, true);
    }
    else if(!fha && fhb){
        auto ans = jia(numA, numB);
        output(ans, false);
    }
    else{
        int tmp = compare(numA, numB);
        if(tmp == 2){
            cout << 0 << endl;
            return;
        }
        else if(tmp == 1){
            auto ans = jian(numA, numB);
            output(ans, false);
        }
        else if(tmp == 0){
            auto ans = jian(numB, numA);
            output(ans, true);
        }
    }
}

int main(){
    int n;cin >> n;
    string null;getline(cin, null);

    for(int i = 0;i < n;i++){
        string numA, numB;
        getline(cin, numA);getline(cin, numB);getline(cin, null);
        minus_string(numA, numB);
    }

    return 0;
}