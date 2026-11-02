#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> graph(n, 0);
    for(int i = 0;i < n;i++){
        int tmp;scanf("%d", &tmp);
        graph[i] = tmp;
    }

    int max = 0;
    vector<int> stack_left;
    vector<int> stack_right;
    vector<int> left_idx(n);
    vector<int> right_idx(n);

    // process left_idx
    for(int i = 0;i < n;i++){
        if(stack_left.size() == 0){
            stack_left.push_back(i);
            left_idx[i] = -1;
            continue;
        }
        while(graph[i] <= graph[stack_left[stack_left.size() - 1]]){
            stack_left.pop_back();
            if(stack_left.size() == 0) break;
        }
        if(stack_left.size() == 0){
            stack_left.push_back(i);
            left_idx[i] = -1;
            continue;
        }
        stack_left.push_back(i);
        left_idx[i] = stack_left[stack_left.size() - 2];
    }

    // process right index
    for(int i = graph.size() - 1;i >= 0;i--){
        if(stack_right.size() == 0){
            stack_right.push_back(i);
            right_idx[i] = graph.size();
            continue;
        }
        while(graph[i] <= graph[stack_right[stack_right.size() - 1]] && stack_right.size() > 0){
            stack_right.pop_back();
            if(stack_right.size() == 0) break;
        }
        if(stack_right.size() == 0){
            stack_right.push_back(i);
            right_idx[i] = graph.size();
            continue;
        }
        stack_right.push_back(i);
        right_idx[i] = stack_right[stack_right.size() - 2];
    }

    for(int i = 0;i < n;i++){
        if(max < (right_idx[i] - left_idx[i] - 1) * graph[i]) max = (right_idx[i] - left_idx[i] - 1) * graph[i];
    }

    cout << max << endl;
    return 0;
}