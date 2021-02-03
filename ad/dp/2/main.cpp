#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXV 110
#define MAXX 1000000000

using namespace std;

//rt
int n, m;
int a [ MAXV];

//dp
int f [ MAXV];
int f2 [ MAXV];

int main ( )
{
    //sr
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> a [ i];
    }
    for ( int i = 2; i <= m; i ++)
    {
        f [ i] = MAXX;
    }

    //dp
    f [ 0] = 0;
    for ( int i = 1; i <= m; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            if ( i - a [ j] < 0)
            {
                break;
            }
            if ( f [ i - a [ j]] + 1 < f [ i])
            {
                f [ i] = f [ i - a [ j]] + 1;
                f2 [ i] = i - a [ j];
            }
        }
    }

    //sc
    if ( f [ m] >= MAXX)
    {
        printf ( "none\n");
        return 0;
    }
    printf ( "%d\n", f [ m]);
    int i = m;
    //printf ( "%d\n", i);
    while ( i)
    {
        printf ( "%d ", i - f2 [ i]);
        i = f2 [ i];
    }
    return 0;
}