#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

struct User
{
    string username;
    string pass;
    string email;
};

string change_case(string str){
    const int magic_number = 'a' - 'A';
    for(int i = 0;i < str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z') str[i] -= magic_number;
        else if(str[i] >= 'A' && str[i] <= 'Z') str[i] += magic_number;
    }
    return str;
}

int main(){
    string email;
    int n;
    cin >> email;
    cin >> n;
    vector<User> users;
    
    for(int i = 0;i < n;i++){
        User user;
        cin >> user.username >> user.pass >> user.email;
        users.push_back(user);
    }

    int count = 0;

    for(int i = 0;i < users.size();i++){
        if(email == users[i].email){
            cout << users[i].username << ' ' << change_case(users[i].pass) << endl;
            count++;
        }
    }
    if(count == 0) cout << "empty" << endl;
    
    return 0;
}