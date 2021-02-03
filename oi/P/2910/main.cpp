#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1e9

using namespace std;

//rt
int n,m;
int edge [ 110] [ 110];
int way [ 10100];
int ans;

int main ( )
{
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            edge [ i] [ j] = MAX;
        }
        edge [ i] [ i] = 0;
    }
    for ( int i = 1; i <= m; i ++)
    {
        cin>> way [ i];
    }
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            cin>> edge [ i] [ j];
        }
    }

    for ( int k = 1; k <= n; k ++)
    {
        for ( int i = 1; i <= n; i ++)
        {
            for ( int j = 1; j <= n; j ++)
            {
                edge [ i] [ j] = min ( edge [ i] [ j], edge [ i] [ k] + edge [ k] [ j]);
            }
        }
    }

    for ( int i = 1; i < m; i ++)
    {
        ans += edge [ way [ i]] [ way [ i + 1]];
    }
    printf ( "%d\n",ans);
    return 0;
}