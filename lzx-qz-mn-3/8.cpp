#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;

const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;

int ch_to_int(char ch){
    switch (ch)
    {
    case 'I':
        return I;
    case 'V':
        return V;
    case 'X':
        return X;
    case 'L':
        return L;
    case 'C':
        return C;
    case 'D':
        return D;
    case 'M':
        return M;
    default:
        return 0; 
    }
}

int rm_to_int(string rm){
    int sum = 0;
    for(int i = 0;i < rm.length();i++){
        if(i != rm.length() - 1){
            if(rm[i] != 'I' && rm[i] != 'X' && rm[i] != 'C') sum += ch_to_int(rm[i]);
            else if(rm.substr(i, 2) == "IV"){
                sum += 4;
                i++;
            }
            else if(rm.substr(i, 2) == "IX"){
                sum += 9;
                i++;
            }
            else if(rm.substr(i, 2) == "XL"){
                sum += 40;
                i++;
            }
            else if(rm.substr(i, 2) == "XC"){
                sum += 90;
                i++;
            }
            else if(rm.substr(i, 2) == "CD"){
                sum += 400;
                i++;
            }
            else if(rm.substr(i, 2) == "CM"){
                sum += 900;
                i++;
            }
            else sum += ch_to_int(rm[i]);
        }
        else{
            sum += ch_to_int(rm[i]);
        }
    }
    return sum;
}

string int_to_rm(int in){
    string out, in_str;
    while(in > 0){
       if(in >= 1000){
            out += "M";
            in -= 1000;
       }
       else if(in < 1000 && in >= 900){
            out += "CM";
            in -= 900;
       }
       else if(in < 900 && in >= 500){
            out += "D";
            in -= 500;
       }
       else if(in < 500 && in >= 400){
            out += "CD";
            in -= 400;
       }
       else if(in < 400 && in >= 100){
            out += "C";
            in -= 100;
       }
       else if(in < 100 && in >= 90){
            out += "XC";
            in -= 90;
       }
       else if(in < 90 && in >= 50){
            out += "L";
            in -= 50;
       }
       else if(in < 50 && in >= 40){
            out += "XL";
            in -= 40;
       }
       else if(in < 40 && in >= 10){
            out += "X";
            in -= 10;
       }
       else if(in < 10 && in >= 9){
            out += "IX";
            in -= 9;
       }
       else if(in < 9 && in >= 5){
            out += "V";
            in -= 5;
       }
       else if(in < 5 && in >= 4){
            out += "IV";
            in -= 4;
       }
       else if(in < 4 && in >= 1){
            out += "I";
            in -= 1;
       }
    }
    return out;
}

int main(){
    string input;cin >> input;

    if(input[0] >= 'A') cout << rm_to_int(input) << endl;
    else cout << int_to_rm(stoi(input));

    return 0;
}