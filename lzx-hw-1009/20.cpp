#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<algorithm>

struct student
{
    int id;
    double score;
};

bool compare_student(student& a, student& b){
    return a.score > b.score;
}

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<student> students(n, student{.id = -1, .score = 100});

    for(int i = 0;i < students.size();i++){
        scanf("%d", &students[i].id);
        scanf("%lf", &students[i].score);
    }

    sort(students.begin(), students.end(), compare_student);

    printf("%d %g", students[k - 1].id, students[k - 1].score);
    
    return 0;
}