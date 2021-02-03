//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量||struct||class
//邻接矩阵
bool map [ 8] [ 8]
{
    0,1,0,1,1,0,0,0,
    1,0,1,0,1,0,0,0,
    0,1,0,0,0,1,0,0,
    1,0,0,0,0,0,1,0,
    1,1,0,0,0,0,1,0,
    0,0,1,0,0,0,0,0,
    0,0,0,1,1,0,0,1,
    0,0,0,0,0,0,1,0,
};

//已经走过
bool zg  [ 10] = { 0};

//队列
int queue [ 100];
int l = 1, r = 2;

//函数

//主函数
int main ()
{
    //初始化
    queue [ l] = 0;
    zg [ 0] = 1; 
    
    //bfs
    while ( l < r)
    {
        //入队
        for ( int i = 0; i < 8; i ++)
        {
            //找路
            if ( map [ queue [ l]]  [ i])
            {
                //判断走过
                if ( ! zg [ i])
                {
                    queue [ r ++] = i;
                    zg [ i] = 1;
                }
            }
        }
        
        //输出
        printf ( "%d ", queue [ l]);

        //出队
        l ++;
    }

    printf ( "\n");
    return 0;
}