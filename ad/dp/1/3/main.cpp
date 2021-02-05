#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXV 10100
#define MAXX 1000000000

using namespace std;

//rt
int n;
int a [ MAXV];

//dp
int i, j;
int fi [ MAXV], fj [ MAXV];

int main ( )
{
    //sr
    cin>> n;
    for ( int k = 1; k <= n; k ++)
    {
        cin>> a [ k];
    }

    //dp
    //i
    fi [ 0] = -MAXX;
    for ( int k = 1; k <= n; k ++)
    {
        fi [ k] = max ( a [ k], a [ k] + fi [ k - 1]);
    }

    //j
    fj [ n + 1] = -MAXX;
    for ( int k = n; k >= 1; k --)
    {
        fj [ k] = max ( a [ k], a [ k] + fj [ k + 1]);
    }

    //sc
    int ans = - MAXX;
    for ( int k = 1; k <= n; k++)
    {
        for ( int ii = k + 1; ii <= n; ii ++)
        {
            ans = max ( ans, fi [ k] + fj [ ii]);
        }
    }
    printf ( "%d\n", ans);

    return 0;
}