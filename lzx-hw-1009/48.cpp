#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main(){
    vector<vector<int>> bucket(26, vector<int>());
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int book_id;string s = "";
        cin >> book_id >> s;
        for(int j = 0;j < s.length();j++) bucket[s[j] - 'A'].push_back(book_id);
    }

    int max = 0, max_author = 0;
    for(int i = 0;i < 26;i++){
        if(max < bucket[i].size()){
            max = bucket[i].size();
            max_author = i;
        }
    }

    char ch =  max_author + 'A';
    cout << ch << endl << max << endl;
    for(int i = 0;i < bucket[max_author].size();i++){
        cout << bucket[max_author][i] << endl;
    }
    
    return 0;
}