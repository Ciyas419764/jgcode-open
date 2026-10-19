#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

struct Event
{
    int begin, end;
};

bool compare_end(Event a, Event b){
    return a.end < b.end;
}


int main(){
    int n;
    cin >> n;
    vector<Event> events(n);
    for(int i = 0;i < n;i++){
        scanf("%d", &events[i].begin);
        scanf("%d", &events[i].end);
    }
    sort(events.begin(), events.end(), compare_end);

    int index = 0, count = 0;
    vector<Event> available_events;
    available_events.push_back(events[0]);index++;
    for(;index < events.size();index++)
        if(events[index].begin >= available_events[available_events.size() - 1].end) available_events.push_back(events[index]);
    
    cout << available_events.size() << endl;
    return 0;
}