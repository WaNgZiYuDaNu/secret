//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//邻接矩阵
bool map [ 10] [ 10]
{
    0,0,0,0,0,0,0,0,0,0,
    0,0,1,0,1,1,0,0,0,0,
    0,1,0,1,0,1,0,0,0,0,
    0,0,1,0,0,0,1,0,0,0,
    0,1,0,0,0,0,0,1,0,0,
    0,1,1,0,0,0,0,1,0,0,
    0,0,0,1,0,0,0,0,0,0,
    0,0,0,0,1,1,0,0,1,0,
    0,0,0,0,0,0,0,1,0,0,
    0,0,0,0,0,0,0,0,0,0,
};

//标记走过
bool zg [ 10]= { 0};


//函数
//dfs
void dfs ( int i)
{
    for ( int j = 1; j <= 9; j ++)
    {
        if ( ! map [ i] [ j])
        {
            //printf ( "1");
            continue;
        }
        if ( !zg [ j])
        {
            zg [ j] = 1;
            printf ( "%d ", j);
            dfs ( j);
        }
    }
}

//主函数
int main ()
{
    //开始
    printf ( "1 ");
    zg [ 1] = 1;
    dfs ( 1);
    return 0;
}