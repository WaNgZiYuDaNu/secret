#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXV 200000
#define MAXX 2147483647

using namespace std;

//rt
int n; 
int arr [ MAXV];

//dtgh
int f [ MAXV];

int main ( )
{
    //sr
    cin>> n;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> arr [ i];
    }

    //dtgh
    f [ 0] = 0;
    for ( int i = 1; i <= n; i ++)
    {
        f [ i] = max ( f [ i - 1] + arr [ i], arr [ i]);
    }

    //sc
    int ans = f [ 1];
    for ( int i = 1; i <= n; i ++)
    {
        ans = max ( ans, f[ i]);
    }
    printf ( "%d", ans);

    return 0;
}