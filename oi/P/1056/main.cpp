//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//同题干
int m, n, k, l, d;
int x, y, p, q;

//人数
struct chenxiouyuan
{
    //坐标
    int id;
    //人数
    int renshu = 0;
} xx [ 1010], yy [ 1010];

//函数
// cmd
bool cmd1 ( chenxiouyuan a, chenxiouyuan b)
{
    return a. renshu > b. renshu;
}

bool cmd2 ( chenxiouyuan a, chenxiouyuan b)
{
    return a. id < b. id;
}

//主函数
int main ()
{
    
    //输入
    cin >> m >> n >> k >> l >> d;
    //初始化
    for ( int i = 1; i <= m; i ++)
    {
        xx [ i]. id = i;
    }
    for ( int i = 1; i <= n; i ++)
    {
        yy [ i]. id = i;
    }
    for ( int i = 1; i <= d; i ++)
    {
        cin >> x >> y  
            >> p >> q ;
        //更新人数
        //在横排
        if ( x == p)
        {
            yy [ min ( y, q)]. renshu ++;
        }
        //在竖排
        else
        {
            xx [ min ( x, p)]. renshu ++;
        }
    }

    //排序
    sort ( yy + 1, yy + 1 + n, cmd1);
    sort ( xx + 1, xx + 1 + m, cmd1);
    sort ( yy + 1, yy + 1 + l, cmd2);
    sort ( xx + 1, xx + 1 + k, cmd2);
    
    //输出
    for ( int i = 1; i <= k; i ++)
    {
        printf ( "%d ", xx [ i]. id);
    }
    printf ( "\n");
    for ( int i = 1; i <= l; i ++)
    {
        printf ( "%d ", yy [ i]. id);
    }
    printf ( "\n");
    return 0;
}