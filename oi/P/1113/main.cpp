#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXV 10100
#define MAXX 2147483647

using namespace std;

//rt
int n;
int len [ MAXV];
bool edge [ MAXV] [ MAXV];
int jgqt [ MAXV];
int ans [ MAXV];

//tope
int q [ MAXV];
int l, r;        

int main ( )
{
    //sr
    cin>> n;
    for ( int i = 1; i <= n ; i ++)
    {
        int absjdr;
        cin>> absjdr;
        cin>> len [ i];
        while ( 1)
        {
            int a;
            cin>> a;

            if ( ! a)
            {
                break;
            }
            edge [ a] [ i] = 1;
            jgqt [ i] ++;
        }
    }

    //tope
    for( int i = 1; i <= n; i ++)
    {
        if ( ! jgqt [ i])
        {
            q [ ++ r] = i;
            ans [ i] = len [ i];
        }
    }
    while ( l < r)
    {
        int pot = q [ ++ l];

        for ( int i = 1; i <= n; i ++)
        {
            if ( edge [ pot] [ i])
            {
                jgqt [ i] --;
                ans [ i] = max ( ans [ i], ans [ pot] + len [ i]);
                
                if ( ! jgqt [ i])
                {
                    q [ ++ r] = i;
                }
            }
        }
    }

    int sna = 0;
    //int isna = 0;
    for ( int i = 1; i <= n ; i ++)
    {
        //printf ( "%d ", ans [ i]);
        //printf ( "%d ", len [ i]);
        
        sna = max ( sna, ans [ i]);
        /*
        if ( sna != ans [ isna])
        {
            isna = i;
        }
        */
    }
    printf ( "%d\n", sna);

    /*
    for ( int i = 1; i <= n; i ++)
    {
        printf ( "%d ", q [ i]);
    }
    */
    printf ( "\n");
    return 0;
}