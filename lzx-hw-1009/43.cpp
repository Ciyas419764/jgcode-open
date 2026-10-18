#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

struct Point
{
    int x,y;
};

bool is_max(vector<Point> points, Point point){
    for(int i = 0;i < points.size();i++){
        if(points[i].x == point.x && points[i].y == point.y) continue;
        else if(points[i].x >= point.x && points[i].y >= point.y) return false;
    }
    return true;
}

bool compare_points(Point a,Point b){
    return a.x < b.x;
}

int main(){
    vector<Point> points;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int tmpx, tmpy;
        scanf("%d", &tmpx);scanf("%d", &tmpy);
        points.push_back({tmpx, tmpy});
    }

    string answer_str = "";
    vector<Point> answer;
    for(int i = 0;i < n;i++){
        if(is_max(points, points[i])) answer.push_back(points[i]);
    }

    sort(answer.begin(), answer.end(), compare_points);

    for(int i = 0;i < answer.size() - 1;i++){
        cout << '(' << answer[i].x << ',' << answer[i].y << ')' << ',';
    }

    cout << '(' << answer[answer.size() - 1].x << ',' << answer[answer.size() - 1].y << ')' << endl;
    
    return 0;
}