//预处理
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//全局变量
//地图
int n, m;
bool map [ 100] [ 100] = { 0};

//方向数组
int dx [ ] = { 1, 0, -1, 0}, dy [ ] = { 0, -1, 0, 1};


//struct||class
//队列元素
struct queue_struct
{
    //坐标
    int x, y;
    
    //步数
    int ans = 0;
};

//队列
struct queue
{
    //队列
    queue_struct q [ 10050];
    
    //边界
    int l = 0, r = 0;

    //插入
    inline void push ( int x, int y, int ans)
    {
        queue_struct p;
        p. x = x;
        p. y = y;
        p. ans = ans;
        q [ r ++] = p;
        map [ x] [ y] = 1;
    }
} fbfs;


//函数

//主函数
int main ()
{
    //读入
    scanf ( "%d%d", &n, &m);
    for ( int i = 1; i <= n; i ++)
    {
        for ( int j = 1; j <= m; j ++)
        {
            char c;

            scanf ( "%c ", &c);

            if ( c == '#')
            {
                map [ i] [ j] = 1;
            }
        }        
    }
    
    //标记入口
    fbfs. push ( 1, 1, 1);

    //bfs
    while ( fbfs. l != fbfs. r)
    {
        //结束
        if ( ( fbfs. q [ fbfs. l]. x == n) && ( fbfs. q [ fbfs. l]. y == m))
        {
            return 0;
        }
        
        for ( int i = 0; i < 4; i ++)
        {
            //省点代码
            int nx = fbfs. q [ fbfs. l]. x + dx [ i],
                ny = fbfs. q [ fbfs. l]. y + dy [ i];

            //出界和无路可走
            if ( ( nx > n) || ( ny > m) || ( nx <= 0) || ( ny <= 0))
            {
                continue;
            }
            if ( map [ nx] [ ny] )
            {   
                continue;
            }

            //进队
            fbfs. push ( nx, ny, fbfs. q [ fbfs. l]. ans + 1);
        }

        //弹出
        fbfs. l ++;
    };

    //输出
    cout << fbfs. q [ fbfs. r - 1]. ans << endl;
    return 0;
}