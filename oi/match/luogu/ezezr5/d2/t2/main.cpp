#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 1000100

using namespace std;

//rt
int n;
int k [ MAX];
int ans;

int main ( )
{
    //sr
    cin>> n;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> k [ i];
    }

    //暴力
    /*
    for ( int x = 1; x <= n; x ++)
    {
        for ( int y = 1; y <= x ; y ++)
        {
            if ( x == y)
            {
                ans = max ( ans, k [ x] * x);
            }
            else
            {
                ans = max ( min ( k [ x],k [ y]) * ( x + y), ans);
            }
        }
    }
    */
    ans = k [ 1] * ( 2 * n - 1);

    //sc
    printf ( "%d\n", ans);
    return 0;
}