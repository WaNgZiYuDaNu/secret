//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>
#define biggest 0x3f3f3f3f

using namespace std;

//全局变量
//棋盘大小&颜色数量
int m, n;

//棋盘
int map [ 110] [ 110];

//剪枝&记忆化
int f [ 110] [ 110];

//方向数组
int dx [ ] = { 1, 0, -1, 0}, dy [ ] = { 0, -1, 0, 1};

//struct||class
//队列节点
struct queue_struct 
{
    //坐标
    int x, y;

    //颜色&来源
    int c;
    bool f;

    //钱数
    int m;
};

//队列
struct queue
{
    //队列
    queue_struct q [ 110 * 110 * 4];

    //左右边界
    int l = 0, r = 0;

    //入队
    inline void push ( int x, int y, int c, bool f, int m)
    {
        queue_struct p;
        p. x = x;
        p. y = y;
        p. c = c;
        p. f = f;
        p. m = m;
        q [ r ++] = p;
    }
}sdwlb;

//函数
//bfs
void bfs ( )
{
    //跑队
    while ( sdwlb. l < sdwlb. r)
    {
        //省点代码
        queue_struct t = sdwlb. q [ sdwlb. l];
        
        //cout << t. x<< ' '<< t. y<< ' '<< t. c<< ' '<< t. f<< ' '<< t. m<< endl;

        //判断出口
        if ( t. x == m && t. y == m)
        {
            //选择最优
            f [ m] [ m] = 
            min ( t. m, f [ m] [ m]);
        }

        //剪枝
        if ( t. m >= f [ t. x] [ t. y])
        {
            // 出队
            sdwlb. l ++;
            continue;
        }

        //记忆化
        f [ t. x] [ t. y] = t. m;

        //探索
        for ( int i = 0; i < 4; i ++)
        {
            //省点代码
            int nx = t. x + dx [ i], ny = t. y + dy [ i];

            //判断出界
            if ( ( nx > m) || ( ny > m) || ( nx < 1) || ( ny < 1))
            {
                continue;
            }

            //新参数
            int nc, nm;
            bool nf;

            //判断参数
            if ( map [ nx] [ ny] != 2)
            {
                nc = map [ nx] [ ny];
                nf = 1;

                //判断mny
                if ( nc != t. c)
                {
                    nm = t. m + 1;
                }
                else
                {
                    nm = t. m;
                }
            }
            else
            {
                if ( t. f)
                {
                    nc = t. c;
                    nm = t. m + 2;
                    nf = 0;
                }
                else
                {
                    continue;
                }
            }
            
            //入队
            sdwlb. push ( nx, ny, nc, nf, nm);
            
        }
        //出队
        sdwlb. l ++;
    }
}

//主函数
int main ()
{
    //输入
    cin >> m >> n;
    for ( int i = 1; i <= m; i ++)
    {
        for ( int j = 1; j <= m; j ++)
        {
            map [ i] [ j] = 2;
            f [ i] [ j] = biggest;
        }
    }
    for ( int i = 1; i <= n; i ++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        map [ x] [ y] = c;
    }

    //标记入口
    sdwlb. push ( 1, 1, map [ 1] [ 1], 1, 0);

    //bfs
    bfs ( );

    //输出
    //判断到不了
    if ( f [ m] [ m] == biggest)
    {
        printf ( "-1\n");
        return 0;
    }
    printf ( "%d\n", f [ m] [ m]);
    return 0;
}