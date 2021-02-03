#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//rt
double a, b, c, d;


int main ( )
{
    cin>> a>> b>> c>> d;

    for ( double i = -100.00; i <= 100.00; i += 0.01)
    {
        double ans = a * i * i * i + b * i * i + c * i + d;    
        if ( ans <= 1e-2 && ans >= -1e-2)
        {
            printf ( "%.2f ", i);
            i += 0.9;
        }
    }

    printf ( "\n");
    return 0;
}