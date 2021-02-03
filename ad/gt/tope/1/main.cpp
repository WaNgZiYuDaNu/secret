#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXX 510
#define MAX 2147483647

using namespace std;

//rt
int n, m;
bool compatition [ MAXX] [ MAXX];//比没比(图)
int sljc [ MAXX];//输了几场(dist)
int q [ MAXX];
int l, r;
//机制:有环时会在输完之前退出

int main ( )
{   
    //sr
    cin>> n>> m;
    for ( int i = 1; i <= m; i ++)
    {
        int a, b;
        cin>> a>> b;

        compatition [ a] [ b] = 1;
        sljc [ b] ++;
    }

    //tope
    for ( int i = 1; i <= n; i ++)
    {
        if ( ! sljc [ i])
        {
            q [ ++ r] = i;

        }
    }
    while ( l < r)
    {
        int pop_ = q [ ++ l];
        for ( int i = 1; i <= n; i ++)
        {
            if ( compatition [ pop_] [ i])
            {
                sljc [ i] --;
                if ( ! sljc [ i])
                {
                    q [ ++ r] = i;
                }
            }
        }
    }

    //sc
    if ( r != n)
    {
        printf ( "ring is here!\nF*Q!!");
        //return 0;
    }
    for ( int i = 1; i <= n; i ++)
    {
        printf ( "%d ", q [ i]);
    }
    printf ( "\n");
    return 0;
}