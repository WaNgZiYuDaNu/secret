//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//同题意
int n;
int w;
int p [ (int)(3e4 + 10)];

//最大最小
int l, r;

//ans
int ans = 0;

//函数
// 

//主函数
int main ()
{
    //输入
    cin >> w >> n;
    for ( int i = 1; i <= n; i ++)
    {
        cin >> p [ i];
    }

    //排序
    sort ( p + 1, p + 1 + n);

    //选
    l = 1;
    r = n;
    while ( l < r)
    {
        //选好了
        if ( p [ l] + p [ r] <= w)
        {
            //加答案
            ans ++;
            //挪
            l ++;
            r --;
        }
        //没选好
        else
        {
            //加答案
            ans ++;
            //挪
            r --;
        }
    }

    //特判
    if ( l == r)
    {
        ans ++;
    }

    //输出
    printf ( "%d\n", ans);
    return 0;
}