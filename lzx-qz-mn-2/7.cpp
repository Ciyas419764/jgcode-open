#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

struct Pym
{
    int id;
    double growth_rate;
};

bool compare_pym(Pym a, Pym b){
    return a.growth_rate < b.growth_rate;
}

int main(){
    int n;cin >> n;
    vector<Pym> pyms(n);

    for(int i = 0;i < n;i++){
        int id_tmp;double before, after;
        scanf("%d", &id_tmp);scanf("%lf", &before);scanf("%lf", &after);
        pyms[i].id = id_tmp;
        pyms[i].growth_rate = after / before;
    }

    sort(pyms.begin(), pyms.end(), compare_pym);

    int i;double max_delta;int max_delta_idx;
    for(i = 1;i < n;i++){
        if(max_delta < pyms[i].growth_rate - pyms[i - 1].growth_rate){
            max_delta = pyms[i].growth_rate - pyms[i - 1].growth_rate;
            max_delta_idx = i;
        }
    }

    cout << n - max_delta_idx << endl;
    for(int j = max_delta_idx;j < n;j++){
        cout << pyms[j].id << endl;
    }

    cout << max_delta_idx << endl;
    for(int j = 0;j < max_delta_idx;j++){
        cout << pyms[j].id << endl;
    }

    return 0;
}