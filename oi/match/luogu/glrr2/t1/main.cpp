#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

//rt
int n, m;
long long a [ 2010] [ 2010];
int x, y;

int gcd ( int a, int b)
{
    if ( b == 1)
    {
        return 1;
    }
    return gcd ( b, a % b);
}

int main ( )
{
    //输入
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= m; j ++)
        {
            cin>> a [ i] [ j];
        }
    }
    cin>> x>> y;

    if ( a [ x] [ y] == 1)
    {
        printf ( "0");
    }
    else
    {
        printf ( "-1");
    }

    /*
    if ( 
        ( n == 2) && ( m == 2) 
        )
    {
        if ( 
            ( a [ 1] [ 1] == 2)
            )
        {

        }
    }
    */

    printf ( "\n");
    return 0;
}