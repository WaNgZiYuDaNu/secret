#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

//rt
int n,m,z;
int edge [ 110] [ 110];

int main ( )
{
    cin>> n>> m;
    char zzz;
    cin>> zzz;
    if ( zzz == '^')
    {
        m = 1;
    }
    else if ( zzz == 'v')
    {
        m = 2;
    }
    else if ( zzz == '<')
    {
        m = 3;
    }
    else
    {
        m = 4;
    }
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            cin>> zzz;
            if ( zzz == 'X')
            {
                edge [ i] [ j] = 1;
            }
            else if ( zzz == 'O')
            {
                edge [ i] [ j] = 2;
            }
            else
            {
                edge [ i] [ j] = 0;
            }
        }
    }

    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= m; j  ++)
        {
            if ( edge [ i] [ j] == 2)
            {
                if ( z == 1)
                {
                     for ( int k = j - 1; k >= 0; k --)
                     {
                        if ( edge [ i] [ k] == 1)
                        {
                            printf ( "GG\n");
                            return 0;
                        }
                     }
                }
                if ( z == 2)
                {
                     for ( int k = i + 1; k <= n; k ++)
                     {
                        if ( edge [ k] [ j] == 1)
                        {
                            printf ( "GG\n");
                            return 0;
                        }
                     }
                }
                if ( z == 3)
                {
                     for ( int k = i - 1; k >= 0; k --)
                     {
                        if ( edge [ k] [ j] == 1)
                        {
                            printf ( "GG\n");
                            return 0;
                        }
                     }
                }
                if ( z == 4)
                {
                     for ( int k = i + 1; k <= m; k ++)
                     {
                        if ( edge [ k] [ j] == 1)
                        {
                            printf ( "GG\n");
                            return 0;
                        }
                     }
                }
            }   
        }
    }
    printf ( "OK\n");
    return 0;
}