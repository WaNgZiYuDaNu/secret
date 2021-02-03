#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXV 1100

using namespace std;

//rt
int n;
int a [ MAXV];

//dp
int ans [ MAXV];

int main ( )
{
    //sr
    cin>> n;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> a [ i];
    }

    //dp
    for ( int i = n; i >= 1; i --)
    {
        ans [ i] = max ( a [ i], a [ i] + ans [ i + 1]);
    }

    //sc
    int anss = ans [ 1];
    for ( int i = 1; i <= n; i ++)
    {
        anss = max ( anss, ans [ i]);
    }
    printf ( "%d\n", anss);

    return 0;
}