#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

struct PointPair
{
    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;
};

struct Point
{
    int x1;
    int y1;
    int z1;
};


int distance_2(PointPair a){
    return (a.x1 - a.x2) * (a.x1 - a.x2) + (a.y1 - a.y2) * (a.y1 - a.y2) + (a.z1 - a.z2) * (a.z1 - a.z2);
}

bool compare_points_pair(PointPair& a, PointPair& b){
    return distance_2(a) > distance_2(b);
}


int main(){
    int n;
    cin >> n;
    vector<PointPair> PointPairs(n * (n - 1) / 2, PointPair{0, 0, 0, 0, 0, 0});
    vector<Point> Points(n);

    for(int i = 0;i < n;i++){
        cin >> Points[i].x1 >> Points[i].y1 >> Points[i].z1;
    }

    int count = 0;
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++){
            PointPairs[count].x1 = Points[i].x1;
            PointPairs[count].y1 = Points[i].y1;
            PointPairs[count].z1 = Points[i].z1;
            PointPairs[count].x2 = Points[j].x1;
            PointPairs[count].y2 = Points[j].y1;
            PointPairs[count].z2 = Points[j].z1;
            count++;
        }

    sort(PointPairs.begin(), PointPairs.end(), compare_points_pair);

    for(int i = 0;i < n * (n - 1) / 2;i++){
        cout << '(' << PointPairs[i].x1 << ',' << PointPairs[i].y1 << ',' << PointPairs[i].z1 << ')' << '-' << '(' << PointPairs[i].x2 << ',' << PointPairs[i].y2 << ',' << PointPairs[i].z2 << ')' << '=';
        printf("%.2f\n", sqrt(distance_2(PointPairs[i])));
    }
    
    return 0;
}