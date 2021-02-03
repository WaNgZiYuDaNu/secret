#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXV 5000
#define MAXX 2147483647

using namespace std;

//rt
int n, m;
int edge [ MAXV] [ MAXV];
int dist [ MAXV];
int it [ MAXV];
int ans = 0;

int main ( )
{
    //sr + csh
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            edge [ i] [ j] = MAXX;
        }
    }
    for ( int i = 1; i <= m; i ++)
    {
        int a, b, c;
        cin>> a>> b>> c;
        edge [ a] [ b] = c;
        edge [ b] [ a] = c;
    }
    for ( int i = 1; i <= n; i ++)
    {
        dist [ i] = edge [ 1] [ i];
        it [ i] = 1;
    }
    dist [ 1] = 0;
    it [ 1] = 0;

    //prim
    for ( int i = 1; i < n; i ++)
    {
        //找下一个入树的
        int minn = MAXX;
        int no;

        //找
        for ( int j = 1; j <= n; j ++)
        {
            if ( it [ j])
            {
                if ( dist [ j] < minn)
                {
                    minn = dist [ j];
                    no = j;
                } 
            }
        }
        it [ no] = 0;
        ans += dist [ i];

        //松弛
        for ( int j = 1; j <= n; j ++)
        {
            if ( it [ j])
            {
                if ( dist [ i] > edge [ no] [ j])
                dist [ j] = edge [ no] [ j];
            }
        }
    }

    //sc
    printf ( "%d\n", ans);
    return 0 ;
}