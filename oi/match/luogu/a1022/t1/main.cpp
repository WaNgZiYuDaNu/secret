#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//rt
long long m, n, k;
long long ans;

long long gcd ( long long a, long long b)
{
    if ( ! b)
    {
        return 1;
    }
    return gcd ( b, a % b);
}

long long g ( long long a)
{
    int ans = 0;
    int b=a;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            int cnt = 0;
            while(a%i==0)
            {
                a=a/i;
                cnt ++;
            }
            ans = max ( cnt, ans);
        }
    }

    return ans;
}

long long power ( int n)
{
    long long ans = 1;

    for ( int i = 1; i <= k; i ++)
    {
        ans *= n;
    }

    return ans;
}

long long max_ ( long long a, long long b)
{
    if ( a > b)
    {
        return a;
    }
    return b;
}

long long f ( long long n)
{
    return max_ ( m - g ( n) + 1, (long long)(0)) * power ( n);
}

int main ( )
{
    //sr
    cin>> n>> m>> k;

    //main
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= n; j ++)
        {
            ans += f ( gcd ( i, j));

            ans %= 998244353;
        }
    }

    //sc
    printf ( "%lld\n", ans);
    return 0;
}