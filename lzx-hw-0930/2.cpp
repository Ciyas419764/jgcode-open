#include<stdio.h>
using namespace std;

int main(){

    int a,b;
    char ch;

    scanf("%d %d %c", &a, &b, &ch);

    switch (ch)
    {
    case '+':
        printf("%d", a + b);
        return 0;
    case '-':
        printf("%d", a - b);
        return 0;
    case '*':
        printf("%d", a * b);
        return 0;
    case '/':
        if(b != 0) printf("%d", a / b);
        else printf("Divided by zero!");
        return 0;
    
    default:
        printf("Invalid operator!");
    
    }

    return 0;
}