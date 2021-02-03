#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 6e8
#define MAXX 110

using namespace std;

//rt
int n, m;
int dist [ MAXX] [ MAXX];
int ans = MAX;
int edge [ MAXX] [ MAXX];

int main ( )
{
    //sr, init
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            edge [ i] [ j] = MAX;
            dist [ i] [ j] = MAX;
        }
        edge [ i] [ i] = 0;
        dist [ i] [ i] = 0;
    }
    for ( int i = 1; i <= m; i ++)
    {
        int a, b, c;
        cin>> a>> b>> c;
        
        //add
        edge [ a] [ b] = c;
        edge [ b] [ a] = c;
        dist [ a] [ b] = c;
        dist [ b] [ a] = c;
    }
    //floyd
    for ( int k = 1; k <= n; k ++)
    {
        for ( int i = 1; i < k; i ++)
        {
            for ( int j = i + 1; j < k; j ++)
            {
                ans = min ( ans, dist [ i] [ j] + edge [ i] [ k] + edge [ k] [ j]);
            }
        }
        for ( int i = 1; i <= n; i++)
        {
            for ( int j = 1; j <= n; j ++)
            {
                dist [ i] [ j] = min ( dist [ i] [ j] , dist [ i] [ k] + dist [ k] [ j]);
                dist [ j] [ i] = dist [ i] [ j];
            }
        }
    }

    if ( ans == MAX)
    {
        printf ( "No solution.\n");
        return 0;
    }
    printf ( "%d\n", ans);
    return 0;
}