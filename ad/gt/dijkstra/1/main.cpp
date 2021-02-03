#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 0x7fffffff
#define MAXX 1100

using namespace std;

//图
int n, m, q;
int edge [ MAXX] [ MAXX];

//dijikstra

int dist [ MAXX];//存答案
int bd [ MAXX]; //判断松弛

int main ( )
{
    cin>> n>> m>> q;
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 1; j <= n ;j ++)
        {
            edge [ i] [ j] = MAX;
        }
        edge [ i] [ i] = 0;
    }
    for ( int i = 1; i <= m; i ++)
    {
        int a, b, c;
        cin>> a>> b>> c;
        edge [ a] [ b] = c;
    }
    for ( int i = 1; i <= n; i ++)
    {
        dist [ i] = edge [ q] [ n];
        bd [ i] = 1;
    }
    bd [ q] = 0;

    //dijikstra
    for ( int i = 1; i < n; i ++)
    {
        //找最小的
        int minn = MAX;
        int no;
        for ( int j = 1; j <= n; j ++)
        {
            if ( bd [ i])
            {
                if ( dist [ j] < minn)
                {
                    minn = dist [ j];
                    no = j;
                }
            }
        }
        bd [ no] = 0;

        //松弛
        for ( int j = 1; j <= n; j ++)
        {
            if ( edge [ no] [ j] != MAX)
            {
                if ( bd [ i])
                {
                    dist [ i] = min ( dist [ i], edge [ no] [ j] + dist [ no]);
                }
            }
        }
    }

    //sc
    for ( int i = 1; i <= n; i ++)
    {
        printf ( "%d ", dist [ i]);
    }
    printf ( "\n");
    return 0;
}