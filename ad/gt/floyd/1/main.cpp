#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1e9

using namespace std;

//rt
int n,m;
bool edge [ 1100] [ 1100];
int p,q;

int main ( )
{
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            edge [ i] [ j] = 0;
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
                edge [ i] [ j] = edge [ i] [ j] || (edge [ i] [ k] && edge [ k] [ j]);
            }
        }
    }

    for ( int i = 1; i <= n ; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            if ( ! edge [ i] [ j])
            {
                printf ( "touxi\n");
                return 0;
            }
        }
    }
    printf ( "haoziweizhi\n");
    return 0;
}