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
bool slmy [ MAXX];//输(出)了没有
int sc [ MAXX];//输出列表;  无环时可以直接输出
int nsc = 0;//有没有环;  机制:有环时会在输完之前退出

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
    while ( 1)
    {
        bool f = 1;
        for ( int i = 1; i <= n; i ++)
        {
            if ( ! sljc [ i] && ! slmy [ i])
            {
                f = 0;
                sc [ ++ nsc] = i;
                slmy [ i] = 1;
                for ( int j = 1; j <= n; j ++)
                {
                    if ( compatition [ i] [ j])
                    {
                        sljc [ j] --;
                    }
                }
            }
        }

        //printf ( "\n");
        if ( f)
        {
            break;
        }
    }

    //sc
    if ( nsc != n)
    {
        printf ( "ring is here!\nF*Q!!");
        return 0;
    }
    for ( int i = 1; i <= n; i ++)
    {
        printf ( "%d ", sc [ i]);
    }
    printf ( "\n");
    return 0;
}