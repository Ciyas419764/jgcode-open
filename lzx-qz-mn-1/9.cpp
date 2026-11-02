#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

struct Num
{
    vector<int> num = vector<int>(400, 0); // idx 201 : 小数点后第一位
    bool fh; // 1 -> positive  0 -> negetive
};

int to_num(char ch){
    if(ch >= '0' && ch <= '9') return ch - '0';
    else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
    return -1;
}

char to_ch(int num){
    if(num <= 9) return num + '0';
    else return num - 10 + 'A';
}

Num process_string_to_num(string num){
    // find_dot
    int dot_idx = num.length();
    for(int i = 0;i < num.length();i++){
        if(num[i] == '.') dot_idx = i;
    }

    Num out_num;

    if(num[0] == '-') out_num.fh = 0;
    else out_num.fh = 1;

    // process before dot
    for(int i = dot_idx - 1;i >= 0;i--){
        if((num[i] >= '0' && num[i] <= '9') || (num[i] >= 'A' && num[i] <= 'Z')){
            out_num.num[201 + i - dot_idx] = to_num(num[i]);
        }
        else break;
    }

    // process after dot
    for(int i = dot_idx + 1;i < num.length();i++){
        if((num[i] >= '0' && num[i] <= '9') || (num[i] >= 'A' && num[i] <= 'Z')){
            out_num.num[200 + i - dot_idx] = to_num(num[i]);
        }
    }

    return out_num;
}

Num process_PM(Num a, Num b, bool method, int k){ // a - b when method = false ,a + b when method = true, a b must be positive, a - b must be positive.
    Num out_num;
    int jinwei = 0;
    for(int i = 310;i > 90;i--){
        if(method){
            out_num.num[i] = a.num[i] + b.num[i] + jinwei;
            if(out_num.num[i] >= k){
                out_num.num[i] -= k;
                jinwei = 1;
            }
            else jinwei = 0;
        }
        else{
            out_num.num[i] = a.num[i] - b.num[i] - jinwei;
            if(out_num.num[i] < 0){
                out_num.num[i] += k;
                jinwei = 1;
            }
            else jinwei = 0;
        }
    }
    out_num.fh = 1;
    return out_num;
}

bool compare_num(Num a, Num b){ // return a > b, a b must be positive
    for(int i = 90; i < 310;i++){
        if(a.num[i] > b.num[i]) return true;
        else if(a.num[i] < b.num[i]) return false;
    }
    return false;
}

Num process_minus(Num a, Num b, int k){
    if(a.fh == 1 && b.fh == 1){
        if(compare_num(a, b)) return process_PM(a, b, false, k);
        else{
            auto out_num = process_PM(b, a, false, k);
            out_num.fh = 0;
            return out_num;
        }
    }
    else if(a.fh == 0 && b.fh == 1){
        Num out = process_PM(a, b, true, k);
        out.fh = 0;
        return out;
    }
    else if(a.fh == 1 && b.fh == 0){
        return process_PM(a, b, true, k);
    }
    else{
        if(compare_num(b, a)) return process_PM(b, a, false, k);
        else{
            auto out_num = process_PM(a, b, false, k);
            out_num.fh = 0;
            return out_num;
        }
    }
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int k;
        string num_a, num_b;
        cin >> k >> num_a >> num_b;

        auto a = process_string_to_num(num_a);
        auto b = process_string_to_num(num_b);
        auto out = process_minus(a, b, k);

        // 判断结果是否为 0
        bool isZero = true;
        for(int i = 90; i < 310; ++i){
            if(out.num[i] != 0){
                isZero = false;
                break;
            }
        }

        if(isZero){
            cout << 0 << '\n';
            continue;
        }

        // 非零才输出负号，避免输出 -0
        if(!out.fh) cout << '-';

        // 整数部分第一个非零位
        int firstInt = -1;
        for(int i = 90; i <= 200; ++i){
            if(out.num[i] != 0){
                firstInt = i;
                break;
            }
        }

        // 小数部分最后一个非零位
        int lastFrac = -1;
        for(int i = 201; i < 310; ++i){
            if(out.num[i] != 0){
                lastFrac = i;
            }
        }

        // 输出整数部分
        if(firstInt != -1){
            for(int i = firstInt; i <= 200; ++i){
                cout << to_ch(out.num[i]);
            }
        }

        // 只有小数部分存在非零位时才输出小数点和小数
        if(lastFrac != -1){
            cout << '.';
            for(int i = 201; i <= lastFrac; ++i){
                cout << to_ch(out.num[i]);
            }
        }

        cout << '\n';
    }

    return 0;
}