/*../1的链式向前星优化版*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXV 1010
#define MAXX 2147483647

//链式向前星
class lsxqx
{
    //main
    struct main
    {
        int zd;//终点
        main *no = NULL;//链接下一条边
        int bq;//边权
    };
    
    //head
    struct head
    {
        int sum;//有几条边
        main *frist;
    }edge [ MAXV];


    //加边
    void add ( int a, int b, int c)
    {
        new main no;

        no. zd = b;
        no. bq = c;
        no. no = edge [ i]. frist;
        edge [ i]. frist = *no;
    }
    
}