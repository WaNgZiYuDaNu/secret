//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//rt
int n;
int a;
long long ans = 0;
long long darko = 0;

//函数
// 

//主函数
int main ()
{   
    //输入
    cin>> n;
    for ( int i = 1; i <= n; i ++)
    {
        cin>> a;
        //计算
        ans += a;
        darko += ans;
    }

    //输出
    printf ( "%lld\n", darko);
    return 0;
}