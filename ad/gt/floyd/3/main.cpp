#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1e9

using namespace std;

//rt
int n,m;
int edge [ 1100] [ 1100];
int p,q;

//路径
int f [ 1100] [ 1100];

//二分输出
void ep ( int l, int r)
{
    //当锁定之后
    if ( f [ l] [ r] == l)
    {
        printf ( "%d ->", l);
        return ;
    }

    //二分
    ep ( l, f [ l] [ r]);
    ep ( f [ l] [ r], r);
}

int main ( )
{
    //sr
    cin>> n>> m;
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            edge [ i] [ j] = MAX;
            f [ i] [ j] = i;
            f [ j] [ i] = j;
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

    //flody
    for ( int k = 1; k <= n; k ++)
    {
        for ( int i = 1; i <= n; i ++)
        {
            for ( int j = 1; j <= n; j ++)
            {
                if ( edge [ i] [ j] > edge [ i] [ k] + edge [ k] [ j])
                {
                    edge [ i] [ j] = edge [ i] [ k] + edge [ k] [ j];
                    f [ i] [ j] = k;
                    f [ j] [ i] = k;                    
                }
            }
        }
    }

    //sc
    ep ( p, q);
    printf ( "%d\n", q);
    return 0;
}