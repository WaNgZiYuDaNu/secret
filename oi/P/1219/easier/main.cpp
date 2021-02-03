//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//全局变量||struct||class
//皇后数组
int que [ 5];
//ans
int ans = 0;

//函数
//dfs
void dfs ( int nq)
{
    //一种情况
    if ( nq == 5)
    {
        ans ++;
        return ;
    }

    //放皇后
    for ( int i = 1; i <= 4; i ++)
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
    //计算
    dfs ( 1);

    //输出
    printf ( "%d\n", ans);
    return 0;
}