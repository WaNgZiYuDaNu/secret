#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//rt
int n, m;
bool edge [ 1010] [ 1010];
int ans = 0;

//sp3
bool f1;
int l1;

int main ( )
{
    //sr
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= m; j ++)
        {
            cin>> edge [ i] [ j];
        }
    }

    if ( m == 1)
    {
        for ( int i = n; i >= 1; i ++)
        {
            if ( edge [ i] [ 1] != edge [ i - 1] [ 1] )
            {
                l1 = i;
            }
        }
        for ( int i = 1; i <= i; i ++)
        {
            if ( edge [ i] [ 1] == 1 && edge [ i - 1] [ 1] == 0)
            {
                f1 = 1;
            }
            if ( ! edge [ i] [ 1] && f1)
            {
                ans ++;
            }
        }
    }

    //sc
    printf ( "%d\n", ans);
    return 0;
}