#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>

using namespace std;
int main(){
    int n;
    cin >> n;
    list<int> nums;

    for(int i = 0;i < n;i++){
        int tmp;scanf("%d", &tmp);
        nums.push_back(tmp);
    }

    int delete_num;
    cin >> delete_num;

    for(auto it = nums.begin();it != nums.end();){
        if(*it == delete_num){
            auto tmp = it;
            ++it;
            nums.erase(tmp--);
        }
        else ++it;
    }

    for(auto it = nums.begin();it != nums.end();++it){
        auto tmp = nums.end();
        if(it != --tmp) printf("%d ",*it);
        else printf("%d\n", *it);
    }
    
    return 0;
}