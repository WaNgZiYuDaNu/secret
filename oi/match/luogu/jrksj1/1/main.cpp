#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXV 100000

using namespace std;

//st
int n;
int a [ MAXV], f [ MAXV];
struct f_
{
    int num;
    int id;
} b [ MAXV];

//cmd
bool cmd ( f_ a, f_ b)
{
    return a.num < b. num;
}

int main ( )
{
    //sr
    cin>> n;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> a [ i];
    }
    for ( int i = 1; i <= n; i ++)
    {
        cin>> b [ i]. num;
        b [ i]. id = i;
    }
    sort ( b + 1, b + n + 1, cmd);

    //js
    for ( int i = 1; i <= n; i ++)
    {
        //ef
        int l, r;
        while ( l + 1 == r)
        {
            int m = a[ ( l + r) / 2];

            if ( m < a [ i])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        printf ( "%d ", min ( abs ( b [ l]. id - i), abs ( n + b [ l]. id - i)));
    }
    printf ( "\n");

    return 0;
}