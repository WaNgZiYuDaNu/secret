#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXX 2147483647
#define MAXV 101000

using namespace std;

//rt
int n;
double m;
double x [ MAXV], y [ MAXV];
double a [ 6] = { MAXV, MAXV, MAXV, MAXV, MAXV, MAXV};
double ans;


int main ( )
{
    //sr
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> x [ i]>> y [ i];
    }

    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            int f = sqrt ( ( x [ i] - x [ j]) * ( x [ i] - x [ j]) + ( ( y [ i] - y [ j]) * ( y [ i] - y [ j])));
            for ( int i = 1; i <= 5; i ++)
            {
                if ( a [ i] < f)
                {
                    a [ i] = f;
                    break;
                }
            }
        }
    }

    ans = 2 * 3.14 * m + a [ 1] + a [ 2] + a [ 3] + a [ 4] + a [ 5];
    if ( ans + 0.5 > ( int) ( ans) + 1)
    {
        printf ( "%d\n", ( int) ( ans) + 1);
        return 0;
    }
    printf ( "%d\n", ( int) ( ans));
    return 0;
}