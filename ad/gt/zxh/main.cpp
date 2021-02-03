#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1e6

using namespace std;

int n, m;
int edge [ 1010] [ 1010];
int ans = 1;

int main ( )
{
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= m; j ++)
        {
            edge [ i] [ j] = MAXN;
        }
        edge [ i] [ i] = 0;
    }
    for ( int i = 1; i <= m; i ++)
    {
        int a, b, c;
        cin>> a>> b>> c;
        edge [ a] [ b] = c;
    }

    for ( int k = 1; k <= n; k ++)
    {
        for ( int i = 1; i < k; i ++)
        {
            for ( int j = i + 1; j < k; j ++)
            {
                ans = min ( ans, edge [ i] [ k] + edge [ k] [ j] + edge [ i] [ j]);
            }
        }
        for ( int i = 1; i <= n; i ++)
        {
            for ( int j = 1; j <= n; j ++)
            {
                edge [ i] [ j] = min ( edge [ i] [ j], edge [ i] [ k] + edge [ k] [ j]);
            }
        }
    }
    //for ( int k = 1; k <= n; k ++)
    //{
        for ( int i = 1; i <= n; i ++)
        {
            for ( int j = 1 + 1; j <= n; j ++)
            {
                ans = min ( ans, edge [ i] [ j] + edge [ j] [ i]);
            }
        }
    //}

    printf ( "%d\n", ans);
    return 0;
}