#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//rt
int a [ 300100];
int n, w;
int ans;

/*
思路：
    搜索出所有可能的等差数列结果
        使用高斯公式
*/
int a1 = 1, an = 1;

//s2
bool s2 = 1;

int main ( )
{
    //sr
    cin>> n>> w;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> a [ i];
        if ( a [ i] != 1)
        {
            s2 = 0;
        }
    }

    //s0
    if ( n == 2 && w == 2)
    {
        printf ( "0\n");
        return 0;
    }

    //s2
    if ( s2)
    {
        printf ( "0\n");
        return 0;
    }

    //n == 1
    if ( n == 1)
    {
        printf ( "0\n");
        return 0;
    }

    //sl
    while ( a1 <= ( w - n))
    {
        an = a1 + n;

        int gx = ( a1 + an) / 2;
        int la = a1;
        int anss = 0;
        for ( int i = 1; i <= n; i ++)
        {
            if ( a [ i] !=la + gx)
            {
                anss ++;
            }
            la += gx;
        }
        ans = min ( ans, anss);
    }

    //sc
    printf ( "%d\n", ans);
    return 0;
}