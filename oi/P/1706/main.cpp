//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//rt
int n;

//已经选过
bool xg [ 10] = { 0};

//ans
int ans [ 10];

//函数
// dfs
void dfs ( int q)
{
    //判断输出
    if ( q == n)
    {
        for ( int i = 0; i < q; i ++)
        {
            printf ( "%5d", ans [ i]);
        }
        printf ( "\n");
        return ;
    }

    //正文
    for ( int i = 1; i <= n; i ++)
    {
        //判断使用
        if (  ! xg [ i])
        {
            //加入
            ans [ q] = i;

            //套娃
            xg [ i] = 1;
            dfs ( q + 1);
            xg [ i] = 0;
        }
    }
}

//主函数
int main ()
{
    //输入
    cin>> n;

    //dfs
    dfs ( 0);
    return 0;
}
