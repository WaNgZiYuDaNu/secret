#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXV 1100
#define MAXX 2147483647

using namespace std;

//rt
int n, m;
int s [ MAXV];
bool si [ MAXV] [ MAXV];



//tope
int l, r;
int q [ MAXV];
int rd [ MAXV];
bool edge [ MAXV] [ MAXV];
int ans;

int main ( )
{
    //sr
    cin>> n>> m;
    for ( int i = 1; i <= m; i ++)
    {
        cin>> s [ i];
        for ( int j = 1; j <= n; j ++)
        {
            int a;
            cin>> a;
            si [ i] [ a] = 1;;
        }
    }

    for ( int i = 1; i <= m; i ++)
    {   
        int g [ MAXV], bg [ MAXV];
        int cg = 0, cbg = 0;
        for ( int j = 2; j <= s [ i]; j ++)
        {
            if ( si [ i] [ j])
            {
                g [ ++ cg] = j;
            }
            else
            {
                bg [ ++ cbg] = j;
            }
        }

        for ( int j = 1; j <= cg; j ++)
        {
            for ( int k = 1; k <= cbg; k ++)
            {
                edge [ g [ j]] [ bg [ k]];
            }
        }
    }


    //tope
    for ( int i = 1; i <= m; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            if ( edge [ i] [ j])
            {
                rd [ j] ++;
            }
        }
    }

    for ( int i = 1; i <= n; i ++)
    {
        if ( ! rd [ i])
        {
            q [ ++ r] = i;
        }
    }
    while ( l < r)
    {
        int pot = q [ ++ l];

        for ( int i = 1; i <= n; i ++)
        {
            if ( edge [ i] [ j])
            {
                rd [ i] --;
                if ( ! rd [ i])
                {
                    q [ ++ r] = i;
                }
            }
        }
    }
}
