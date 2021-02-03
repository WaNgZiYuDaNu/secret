//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>
#define mv 30
#define mg 20

using namespace std;

//全局变量||struct||class
//维他命
int v;
int vtm [ mv];

//饲料
int g;
int gw [ mg] [ mv];

//当前
int sl [ mg];
int nv [ mv];

//答案
int ag = 0x3f3f3f3f;
int asl [ mg];

//函数
//dfs
void dfs ( int h, int ng)
{
    //取完
    if ( h > g)
    {
        //判断答案
        //判断
        bool f = 1;
        for ( int i = 1; i <= v; i ++)
        {
            if ( nv [ i] < vtm [ i])
            {
                f = 0;
                break;
            }
        }
        //判断最简
        if ( f)
        {
            //判断长度
            if ( ng < ag)
            {
                ag = ng;
                for ( int i = 1; i <= ag; i ++)
                {
                    asl [ i] = sl [ i];
                }
            }
        }
        return ;
    }

    //递归
    //加
    for ( int i = 1; i <= v; i ++)
    {
        nv [ i] += gw [ h] [ i];
    }
    sl [ ng + 1] = h;
    dfs ( h + 1, ng + 1);

    //不加
    for ( int i = 1; i <= v; i ++)
    {
        nv [ i] -= gw [ h] [ i];
    }
    dfs ( h + 1, ng);
}

//主函数
int main ()
{ 
    //输入
    cin >> v;
    for ( int i = 1; i <= v; i ++)
    {
        cin >> vtm [ i];
    }
    cin >> g;
    for ( int i = 1; i <= g; i ++)
    {
        for ( int j = 1; j <= v; j ++)
        {
            cin >> gw [ i] [ j];
        }
    }

    //dfs
    dfs ( 1, 0);

    //输出
    printf ( "%d ", ag);
    for ( int i = 1; i <= ag; i ++)
    {
        printf ( "%d ", asl [ i]);
    }
    printf ( "\n");
    return 0;
}