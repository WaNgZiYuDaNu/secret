//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 15

using namespace std;

//全局变量||struct||class
//大小
int n;
//皇后数组
int que [ MAX];
//ans
int ans = 0;

//函数
//dfs
void dfs ( int nq)
{
    //一种情况
    if ( nq == n + 1)
    {
        ans ++;
        //输出前三个
        if ( ans <= 3)
        {
            for ( int i = 1; i <= n; i ++)
            {
                printf ( "%d ", que [ i]);
            }
            printf ( "\n");
        }
        return ;
    }

    //放皇后
    for ( int i = 1; i <= n; i ++)
    {
        //枚举每个已放皇后
        bool f = 1;
        for ( int j = 1; j < nq; j ++)
        {
            //同一列
            if ( i == que [ j])
            {
                f = 0;
                break;
            }
            //同一斜线
            if ( abs ( nq - j) == 
                abs ( i - que [ j]))
            {
                f = 0;
            }
        }
        //往下走
        if ( f)
        {
            que [ nq] = i;
            dfs ( nq + 1);
        }
    }
    return ;
}

//主函数
int main ()
{
    cin >> n;

    //计算
    dfs ( 1);

    //输出
    printf ( "%d\n", ans);
    return 0;
}