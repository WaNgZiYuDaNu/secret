#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1e9

using namespace std;

//rt
int n,m;
int edge [ 1100] [ 1100];
int p,q;

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
        int a, b, c;
        cin>> a>> b>> c;
        edge [ a] [ b] = c;
        edge [ b] [ a] = c;
    }
    cin>> p>> q;

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

    printf ( "%d\n",edge [ p] [ q]);
    return 0;
}